# Evaluación de código C

Ejercicio 3 del bloque 1
# rats
Entries in perl database: 33
Entries in ruby database: 46
Entries in python database: 62
Entries in c database: 334
Entries in php database: 55
Analyzing ./practicas-DPS/ejercicio_evaluacion_c/ejemplo3erroneo.c
Total lines analyzed: 15
Total time 0.000059 seconds
254237 lines per second

# cppchecker
Checking ejemplo3erroneo.c ...
ejemplo3erroneo.c:5:0: style: The function 'func' is never used. [unusedFunction]

^

# splint
ejemplo3erroneo.c: (in function func)
ejemplo3erroneo.c:9:8: Fall through case (no preceding break)
  Execution falls through from the previous case (use /*@fallthrough@*/ to mark
  fallthrough cases). (Use -casebreak to inhibit warning)
ejemplo3erroneo.c:11:11: Fall through case (no preceding break)
ejemplo3erroneo.c:7:13: Statement after switch is not a case: int i = 4
  The first statement after a switch is not a case. (Use -firstcase to inhibit
  warning)

# vera++
ejemplo3erroneo.c:1: T013: no copyright notice found
ejemplo3erroneo.c:6: L002: horizontal tab used
ejemplo3erroneo.c:6: T008: keyword 'switch' not followed by a single space
ejemplo3erroneo.c:7: L002: horizontal tab used
ejemplo3erroneo.c:8: L002: horizontal tab used
ejemplo3erroneo.c:9: L002: horizontal tab used
ejemplo3erroneo.c:10: L002: horizontal tab used
ejemplo3erroneo.c:11: L002: horizontal tab used
ejemplo3erroneo.c:12: L002: horizontal tab used
ejemplo3erroneo.c:13: L002: horizontal tab used
ejemplo3erroneo.c:13: T011: closing curly bracket not in the same line or column
ejemplo3erroneo.c:14: T011: closing curly bracket not in the same line or column

# valgrind
==19752== Memcheck, a memory error detector
==19752== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==19752== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info
==19752== Command: /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3
==19752== Parent PID: 12682
==19752== 
==19752== Conditional jump or move depends on uninitialised value(s)
==19752==    at 0x48D7EE0: __vfprintf_internal (vfprintf-internal.c:1516)
==19752==    by 0x48C43DA: printf (printf.c:33)
==19752==    by 0x109169: func (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752==    by 0x109184: main (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752== 
==19752== Use of uninitialised value of size 8
==19752==    at 0x48BE5BB: _itoa_word (_itoa.c:177)
==19752==    by 0x48D7AF3: __vfprintf_internal (vfprintf-internal.c:1516)
==19752==    by 0x48C43DA: printf (printf.c:33)
==19752==    by 0x109169: func (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752==    by 0x109184: main (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752== 
==19752== Conditional jump or move depends on uninitialised value(s)
==19752==    at 0x48BE5CC: _itoa_word (_itoa.c:177)
==19752==    by 0x48D7AF3: __vfprintf_internal (vfprintf-internal.c:1516)
==19752==    by 0x48C43DA: printf (printf.c:33)
==19752==    by 0x109169: func (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752==    by 0x109184: main (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752== 
==19752== Conditional jump or move depends on uninitialised value(s)
==19752==    at 0x48D8533: __vfprintf_internal (vfprintf-internal.c:1516)
==19752==    by 0x48C43DA: printf (printf.c:33)
==19752==    by 0x109169: func (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752==    by 0x109184: main (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752== 
==19752== Conditional jump or move depends on uninitialised value(s)
==19752==    at 0x48D7C4F: __vfprintf_internal (vfprintf-internal.c:1516)
==19752==    by 0x48C43DA: printf (printf.c:33)
==19752==    by 0x109169: func (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752==    by 0x109184: main (in /home/allamb00/ULE/DPS/practicas-DPS/ejercicio_evaluacion_c/ejemplo3)
==19752== 
==19752== 
==19752== HEAP SUMMARY:
==19752==     in use at exit: 0 bytes in 0 blocks
==19752==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==19752== 
==19752== All heap blocks were freed -- no leaks are possible
==19752== 
==19752== Use --track-origins=yes to see where uninitialised values come from
==19752== For lists of detected and suppressed errors, rerun with: -s
==19752== ERROR SUMMARY: 7 errors from 5 contexts (suppressed: 0 from 0)
