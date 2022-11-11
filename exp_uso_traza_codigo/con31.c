#include <stdatomic.h>
#include <stddef.h>
#include <threads.h>

mtx_t lock;
/* Atomic so multiple threads can modify safely */
atomic_int completed = ATOMIC_VAR_INIT(0);
enum { max_threads = 5 };

int do_work(void *arg) {
  int *i = (int *)arg;
  /*  A continuación se van iniciando y bloqueando los hilos creados en
   *  main en función del número que se les asigna en la creación en main,
   *  confiando en que los hilos van a llegar en el mismo orden de creación,
   *  provocando una condición de carrera. La solución más sencilla es iniciar
   *  el mutex en el hilo principal ANTES de crear todos los hilos y destruir el
   *  mutex DESPUÉS de haber bloqueado todos los hilos, de forma que nos aseguramos
   *  que el mutex no va a ser destruido después de haber sido desbloqueado
   */
  if (*i == 0) { /* Creation thread */
    if (thrd_success != mtx_init(&lock, mtx_plain)) {
      /* Handle error */
    }
    atomic_store(&completed, 1);
  } else if (*i < max_threads - 1) { /* Worker thread */
    if (thrd_success != mtx_lock(&lock)) {
      /* Handle error */
    }
    /* Access data protected by the lock */
    atomic_fetch_add(&completed, 1);
    if (thrd_success != mtx_unlock(&lock)) {
      /* Handle error */
    }
  } else { /* Destruction thread */
    mtx_destroy(&lock); /*  Es posible que se ejecute esta sentencia   */
  }			/*  cuando no han terminado el resto de hilos  */
  return 0;
}

int main(void) {
  thrd_t threads[max_threads];

  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_create(&threads[i], do_work, &i)) { /*  Se crean los hilos y se confía en que */
      /* Handle error  */					 /*  se ejecuten en el mismo orden         */
    }
  }
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_join(threads[i], 0)) {
      /* Handle error */
    }
  }
  return 0;
}
