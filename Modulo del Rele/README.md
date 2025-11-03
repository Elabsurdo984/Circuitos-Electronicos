# Módulo de Control de Relé con Transistor

## Descripción General
Este circuito implementa un **módulo de control de relé** que permite controlar cargas de alta potencia (como motores, lámparas, electrodomésticos) mediante una señal de bajo voltaje. Utiliza un transistor NPN para activar el relé y un interruptor deslizante para control manual.

## Componentes Requeridos

| Componente | Cantidad | Especificación |
|-----------|----------|---------------|
| K1 | 1 | Relé SPDT (Polo simple, doble tiro) |
| T1 | 1 | Transistor NPN (BJT) (ej. 2N2222, BC547) |
| D1 | 1 | Diodo (ej. 1N4007, 1N4148) |
| D2 | 1 | LED Verde |
| R1 | 1 | Resistor de 1 kΩ |
| R3 | 1 | Resistor de 220 Ω |
| S1 | 1 | Interruptor deslizante |
| P1 | 1 | Fuente de alimentación 5V, 5A |

## Descripción del Circuito

### Cómo Funciona

El circuito utiliza un transistor como **interruptor electrónico** para activar el relé. El interruptor deslizante S1 controla cuando el relé debe activarse, y el LED verde indica visualmente el estado del sistema.

#### Principio de Operación

**Cuando el interruptor está APAGADO (S1 abierto):**
- No hay corriente hacia la base del transistor
- El transistor está en **corte** (apagado)
- No fluye corriente por la bobina del relé
- El relé está **desactivado** (contactos en posición NC - Normalmente Cerrado)
- El LED verde está **APAGADO**

**Cuando el interruptor está ENCENDIDO (S1 cerrado):**
- La corriente fluye a través de R1 hacia la base del transistor
- El transistor entra en **saturación** (encendido)
- Fluye corriente por la bobina del relé (a través del colector-emisor)
- El relé se **activa** (contactos cambian a posición NO - Normalmente Abierto)
- El LED verde está **ENCENDIDO**

### Función de los Componentes

- **S1 (Interruptor deslizante)**: Control manual para activar/desactivar el relé

- **R1 (1 kΩ)**: Resistor limitador de corriente de base del transistor
  - Protege el transistor y limita la corriente a ~4-5 mA

- **T1 (Transistor NPN)**: Actúa como interruptor electrónico
  - Amplifica la pequeña corriente de base para activar el relé
  - Permite controlar corrientes altas (relé) con señales bajas (interruptor)

- **K1 (Relé SPDT)**: Interruptor electromagnético
  - Permite controlar circuitos completamente aislados
  - SPDT: tiene 3 terminales (Común, NC, NO)
  - Típicamente puede conmutar 120-240V AC o cargas de varios amperios

- **D1 (Diodo de protección)**: Diodo de rueda libre o flyback
  - **MUY IMPORTANTE**: Protege el transistor de picos de voltaje
  - Cuando el relé se desactiva, la bobina genera un voltaje inverso que podría dañar el transistor
  - Conectado en antiparalelo con la bobina del relé (cátodo a positivo, ánodo a colector)

- **D2 (LED Verde)**: Indicador visual de estado
  - Se enciende cuando el relé está activado

- **R3 (220 Ω)**: Resistor limitador de corriente para el LED
  - Limita la corriente a aproximadamente 15-20 mA

## Diagrama de Estados

| Interruptor S1 | Transistor | Relé | LED Verde | Contactos Relé |
|----------------|------------|------|-----------|----------------|
| Apagado | Corte | Desactivado | Apagado | Posición NC |
| Encendido | Saturación | Activado | Encendido | Posición NO |

## Conexiones del Relé SPDT

El relé tiene 3 contactos principales:
- **COM (Común)**: Terminal común que se conecta a la carga
- **NC (Normalmente Cerrado)**: Conectado a COM cuando el relé está desactivado
- **NO (Normalmente Abierto)**: Conectado a COM cuando el relé está activado

Adicionalmente tiene 2 terminales para la bobina (controlados por el transistor).

## Aplicaciones Prácticas

Este módulo es fundamental para:

1. **Control de cargas AC**: Controlar lámparas, ventiladores, calentadores de 120/220V
2. **Automatización del hogar**: Integrar con sensores (LDR, temperatura, movimiento)
3. **Control remoto**: Activar dispositivos mediante microcontroladores (Arduino, ESP32)
4. **Sistemas de seguridad**: Activar alarmas, cerraduras eléctricas
5. **Protección de circuitos**: Aislar completamente el circuito de control de la carga

## Ventajas del Uso de Relé

- **Aislamiento galvánico**: El circuito de control está completamente aislado de la carga
- **Versatilidad**: Puede controlar AC o DC, alto o bajo voltaje
- **Alta corriente**: Puede manejar cargas de varios amperios
- **Confiabilidad**: Contactos físicos sin componentes semiconductores en la carga

## Notas de Construcción Importantes

### ⚠️ CRÍTICO - Diodo de Protección
- **SIEMPRE** instale el diodo D1 en antiparalelo con la bobina del relé
- Polaridad: Cátodo (banda) hacia el positivo, ánodo hacia el colector del transistor
- Sin este diodo, el transistor puede dañarse al desactivar el relé

### Conexión del Transistor NPN
- **Base (B)**: Conectada a S1 y R1
- **Colector (C)**: Conectado a un terminal de la bobina del relé y al ánodo de D1
- **Emisor (E)**: Conectado a tierra (GND)

### Consideraciones de Potencia
- Verifique que el transistor pueda manejar la corriente de la bobina del relé (típicamente 30-80 mA)
- El relé debe ser de 5V para coincidir con la alimentación
- Para cargas mayores, use relés con mayor capacidad de corriente

## Especificaciones Típicas

**Relé 5V SPDT:**
- Voltaje de bobina: 5V DC
- Corriente de bobina: 70-80 mA
- Capacidad de contactos: 10A @ 250V AC o 10A @ 30V DC
- Resistencia de bobina: ~70 Ω

## Alimentación

- **Voltaje**: 5V DC
- **Consumo**: 
  - Relé desactivado: <5 mA (solo LED si está en paralelo)
  - Relé activado: ~100 mA (bobina + LED)
- Conecte P1+ a VCC y P1- a GND

## Expansiones Posibles

Este módulo puede expandirse para:
- Reemplazar S1 con salida de microcontrolador (Arduino, Raspberry Pi)
- Agregar sensores (LDR, PIR, temperatura) en lugar del interruptor
- Controlar múltiples relés para diferentes cargas
- Añadir optoacoplador para mayor aislamiento
- Implementar control PWM para cargas variables

## Advertencias de Seguridad

⚠️ **Si usa el relé para controlar voltajes AC (120/220V):**
- Tenga extremo cuidado con las conexiones de alto voltaje
- Use cables adecuados y aislados
- Nunca toque los contactos con el sistema energizado
- Consulte regulaciones eléctricas locales
- Considere usar una caja aislante para el circuito