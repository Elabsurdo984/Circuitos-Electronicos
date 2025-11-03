# Implementación de Compuerta NOT con Compuertas NAND

## Descripción General
Este circuito demuestra cómo implementar una compuerta NOT (inversor) utilizando una compuerta NAND, junto con indicadores LED visuales para mostrar los estados de entrada y salida.

## Componentes Requeridos

| Componente | Cantidad | Especificación |
|-----------|----------|---------------|
| U1 | 1 | Compuerta NAND cuádruple (ej. 74HC00) |
| S1 | 1 | Pulsador |
| D1 | 1 | LED Rojo (indicador de entrada) |
| D2 | 1 | LED Verde (indicador de salida) |
| R1, R2 | 2 | Resistores de 1 kΩ |
| R3 | 1 | Resistor de 220 Ω |
| P1 | 1 | Fuente de alimentación 5V, 2.6A |

## Descripción del Circuito

### Cómo Funciona

El circuito utiliza una propiedad fundamental de la lógica digital: **una compuerta NAND con ambas entradas conectadas juntas se comporta como una compuerta NOT (inversor)**.

#### Explicación Lógica
- Cuando ambas entradas de una compuerta NAND están unidas, siempre reciben la misma señal
- Tabla de verdad NAND para entradas idénticas:
  - Si A = B = 0 → Salida = 1
  - Si A = B = 1 → Salida = 0
- ¡Esto es exactamente el comportamiento de una compuerta NOT!

#### Operación del Circuito

**Cuando el botón NO está presionado (S1 abierto):**
- Los pines de entrada (1A y 1B) están en nivel BAJO a través de R1
- El LED rojo (D1) está **apagado** (entrada = 0)
- La salida de la NAND (1Y) está en nivel ALTO
- El LED verde (D2) está **encendido** (salida = 1)

**Cuando el botón está presionado (S1 cerrado):**
- Los pines de entrada (1A y 1B) se conectan a VCC (nivel ALTO)
- El LED rojo (D1) está **encendido** (entrada = 1)
- La salida de la NAND (1Y) está en nivel BAJO
- El LED verde (D2) está **apagado** (salida = 0)

### Función de los Componentes

- **R1 (1 kΩ)**: Resistor de pull-down que mantiene la entrada en BAJO cuando el botón no está presionado
- **R2 (1 kΩ)**: Resistor limitador de corriente para el LED rojo (indicador de entrada)
- **R3 (220 Ω)**: Resistor limitador de corriente para el LED verde (indicador de salida)
- **D1 (LED Rojo)**: Indica cuando la entrada está en nivel ALTO
- **D2 (LED Verde)**: Indica cuando la salida está en nivel ALTO

## Diagrama de Estados

| Botón S1 | Entrada (1A, 1B) | LED Rojo | Salida (1Y) | LED Verde |
|----------|------------------|----------|-------------|-----------|
| No presionado | 0 | Apagado | 1 | Encendido |
| Presionado | 1 | Encendido | 0 | Apagado |

## Aplicaciones

Este circuito demuestra:
1. **Universalidad de las compuertas NAND**: Cualquier función lógica puede construirse usando solo compuertas NAND
2. **Lógica inversa**: Concepto fundamental en diseño digital
3. **Indicadores visuales**: Útil para depuración y demostración de circuitos lógicos

## Notas de Construcción

- Asegúrese de que la polaridad de los LEDs sea correcta (ánodo al positivo, cátodo al negativo)
- Verifique las conexiones de alimentación del chip NAND (VCC y GND)
- El resistor de 220 Ω puede ajustarse según el brillo deseado del LED verde
- Las resistencias de 1 kΩ proporcionan una corriente adecuada para los LEDs comunes

## Alimentación

- **Voltaje**: 5V DC
- **Corriente**: Máximo 2.6A (aunque el circuito consume mucho menos)
- Conecte P1+ a VCC y P1- a GND