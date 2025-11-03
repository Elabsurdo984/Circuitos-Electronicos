# Circuito Básico de LED con Transistor y Pulsador

## Descripción General
Este es un circuito básico educativo que demuestra el funcionamiento de un **transistor como interruptor electrónico**. Al presionar un pulsador, se activa el transistor que enciende un LED. Es ideal para aprender los fundamentos de la electrónica digital y el control de cargas con transistores.

## Componentes Requeridos

| Componente | Cantidad | Especificación |
|-----------|----------|---------------|
| T1 | 1 | Transistor NPN (BJT) (ej. 2N2222, BC547, 2N3904) |
| D1 | 1 | LED Rojo |
| R1 | 1 | Resistor de 330 Ω |
| R2 | 1 | Resistor de 10 kΩ |
| S1 | 1 | Pulsador (push button) |
| BAT1 | 1 | Batería de 9V |

## Descripción del Circuito

### Cómo Funciona

El circuito utiliza un transistor NPN como **interruptor controlado por corriente**. Una pequeña corriente a través de la base del transistor controla una corriente mucho mayor entre colector y emisor, lo que demuestra el efecto de **amplificación de corriente** del transistor.

#### Principio de Operación

**Cuando el pulsador NO está presionado (S1 abierto):**
- No hay corriente hacia la base del transistor
- El transistor está en **corte** (apagado)
- No fluye corriente entre colector y emisor
- El LED rojo está **APAGADO**

**Cuando el pulsador está presionado (S1 cerrado):**
- La corriente fluye desde la batería a través de R2 hacia la base del transistor
- Corriente de base ≈ (9V - 0.7V) / 10kΩ ≈ 0.83 mA
- El transistor entra en **saturación** (encendido)
- Fluye corriente desde el colector hacia el emisor
- La corriente pasa por el LED y R1
- El LED rojo está **ENCENDIDO**

### Función de los Componentes

- **S1 (Pulsador)**: Interruptor momentáneo que controla la activación del transistor
  - Al presionar, conecta la base del transistor a VCC
  - Al soltar, el transistor se desactiva

- **R2 (10 kΩ)**: Resistor limitador de corriente de base
  - Protege el transistor limitando la corriente de base a ~0.8 mA
  - Determina el punto de operación del transistor
  - Valor típico: entre 1 kΩ y 47 kΩ

- **T1 (Transistor NPN)**: Interruptor electrónico y amplificador de corriente
  - Requiere ~0.7V en la unión base-emisor para activarse
  - **Ganancia (hFE)**: típicamente 100-300
  - Una pequeña corriente de base controla una corriente mucho mayor de colector

- **R1 (330 Ω)**: Resistor limitador de corriente para el LED
  - Protege el LED de corriente excesiva
  - Corriente LED ≈ (9V - 2V - 0.2V) / 330Ω ≈ 20 mA
  - Valor seguro para LEDs comunes (20 mA máximo)

- **D1 (LED Rojo)**: Indicador visual
  - Voltaje directo típico: ~2V
  - Corriente nominal: 20 mA

- **BAT1 (Batería 9V)**: Fuente de alimentación portátil
  - Proporciona suficiente voltaje para el LED y transistor
  - Capacidad típica: 400-600 mAh

## Análisis del Circuito

### Cálculos de Corriente

**Corriente de Base (IB):**
```
IB = (VCC - VBE) / R2
IB = (9V - 0.7V) / 10kΩ
IB ≈ 0.83 mA
```

**Corriente de Colector (IC):**
```
IC = (VCC - VLED - VCE(sat)) / R1
IC = (9V - 2V - 0.2V) / 330Ω
IC ≈ 20.6 mA
```

**Ganancia requerida del transistor:**
```
hFE mínimo = IC / IB
hFE = 20.6 mA / 0.83 mA
hFE ≈ 25
```

Cualquier transistor NPN común tiene ganancia suficiente (típicamente >100).

## Diagrama de Estados

| Pulsador S1 | Corriente Base | Estado Transistor | Corriente LED | LED |
|-------------|----------------|-------------------|---------------|-----|
| No presionado | 0 mA | Corte (OFF) | 0 mA | Apagado |
| Presionado | ~0.8 mA | Saturación (ON) | ~20 mA | Encendido |

## Conexiones del Transistor NPN

Identificación de terminales (vista frontal, patas hacia abajo):
- **Emisor (E)**: Terminal izquierdo - conectado a GND
- **Base (B)**: Terminal central - conectado a R2 y S1
- **Colector (C)**: Terminal derecho - conectado a R1 y LED

**Conexiones:**
- **Base**: Pulsador (S1) → R2 → Base
- **Colector**: Batería (+) → R1 → LED → Colector
- **Emisor**: Emisor → Batería (-)

## Aplicaciones Educativas

Este circuito enseña:

1. **Funcionamiento del transistor**: Como interruptor y amplificador
2. **Control de cargas**: Una señal pequeña controla una carga mayor
3. **Polarización de transistor**: Voltajes y corrientes necesarias
4. **Limitación de corriente**: Importancia de resistores protectores
5. **Interacción humano-circuito**: Control mediante pulsador

## Ventajas del Transistor sobre un Interruptor Directo

- **Amplificación**: Pequeña corriente controla corriente mayor
- **Control remoto**: La base puede conectarse a sensores o microcontroladores
- **Velocidad**: Puede conmutar millones de veces por segundo
- **Sin desgaste mecánico**: No hay contactos físicos que se deterioren
- **Base para lógica digital**: Fundamento de computadoras y sistemas digitales

## Modificaciones Posibles

### Ajustar Brillo del LED
- **Aumentar R1**: Reduce corriente y brillo (ej. 470Ω, 1kΩ)
- **Disminuir R1**: Aumenta corriente y brillo (mínimo 220Ω para 9V)

### Cambiar el Pulsador
- Reemplazar S1 por:
  - Sensor (LDR, termistor)
  - Salida de microcontrolador (Arduino, Raspberry Pi)
  - Otro transistor (cascada Darlington)

### Controlar Otras Cargas
- Reemplazar LED por:
  - Buzzer o zumbador
  - Motor DC pequeño (agregar diodo de protección)
  - Múltiples LEDs en serie/paralelo

### Hacer el LED Intermitente
- Agregar un capacitor entre base y emisor para crear retardo
- Implementar circuito multivibrador astable con dos transistores

## Notas de Construcción

### Polaridad del LED
- **Ánodo (+)**: Pata larga, conectada a R1
- **Cátodo (-)**: Pata corta, conectada al colector del transistor
- Si el LED no enciende, verifique la polaridad

### Identificación del Transistor
Para transistores comunes (2N2222, BC547):
- Vista frontal (lado plano hacia ti), patas hacia abajo
- Orden: E-B-C (Emisor-Base-Colector) de izquierda a derecha

### Prueba del Circuito
1. Conecte la batería
2. **Sin presionar**: LED debe estar apagado
3. **Al presionar**: LED debe encender inmediatamente
4. **Al soltar**: LED debe apagar inmediatamente

## Consumo de Energía

**LED apagado:** ~0 mA (consumo despreciable)
**LED encendido:** ~21 mA

**Duración de batería 9V (500 mAh):**
- Uso continuo: ~24 horas
- Uso intermitente: varios días o semanas

## Conceptos Importantes

### El Transistor como Interruptor
- **Corte**: VBE < 0.7V → Transistor apagado (interruptor abierto)
- **Activa**: VBE ≥ 0.7V → Transistor parcialmente encendido
- **Saturación**: IB suficiente para IC máxima → Transistor totalmente encendido (interruptor cerrado)

### Ganancia de Corriente (hFE o β)
```
IC = hFE × IB
```
Un transistor típico amplifica la corriente de base 100-300 veces.

## Expansiones Futuras

Este circuito básico es el punto de partida para:
- Multivibradores astables (LEDs intermitentes)
- Amplificadores de audio
- Fuentes de corriente constante
- Compuertas lógicas discretas
- Osciladores y temporizadores
- Control de motores y relés

## Seguridad

✓ **Circuito de bajo voltaje (9V)**: Completamente seguro al tacto
✓ **Batería común**: Fácil de conseguir y reemplazar
✓ **Sin riesgo eléctrico**: Ideal para principiantes y estudiantes

---

**Este circuito es perfecto para comenzar en electrónica y entender cómo funcionan los transistores como bloques fundamentales de todos los dispositivos electrónicos modernos.**