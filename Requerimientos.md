## Requerimientos

### Sistema
- RF1: El sistema analiza los datos históricos de venta de mínimo 2 años.

- RF2: El sistema busca pronósticos estadísticos utilizando algoritmos de regresión lineal simple.

- RNF2: Los datos históricos deben generar patrones estadísticos simples.

- RF3: El sistema crea una base de datos dinámica con las ventas semanales.

- RNF3: El sistema únicamente almacena datos flotantes.

- RF4: El sistema determina cuáles son las temporadas bajas de ventas.

- RNF4: Las temporadas tienen una duración de una semana.

- RF5: El sistema compara las ventas semanales actuales con las del año anterior.

- RNF6: El sistema calcula al final de la semana el total de la temporada.

- RF6: El sistema notifica al usuario en caso de temporada baja o riesgo de temporada baja.

- RNF7: La notificación se realiza los domingos a las 12 pm. Una vez realizada no puede repetirse.

- RF7: El programa sugiere posibles soluciones al usuario para aumentar las ventas.

- RNF8: Las soluciones son cadenas de texto impresas prediseñadas. No varían.

### Usuario
- RNF1: La empresa debe contar con datos históricos de mínimo 2 años.

- RNF5: El usuario introduce los ingresos diarios de la empresa.
