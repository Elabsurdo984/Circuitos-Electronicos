# Circuito Sensor de Luz con Transistor

## Descripción General
Este circuito implementa un sensor de luz automático que enciende un LED cuando disminuye la luz ambiente. Utiliza una fotorresistencia (LDR) como sensor y un transistor NPN como interruptor controlado por luz.

## Componentes Requeridos

| Componente | Cantidad | Especificación |
|-----------|----------|---------------|
| R1 | 1 | Fotorresistencia (LDR) |
| R2 | 1 | Resistor de 10 kΩ |
| T1 | 1 | Transistor NPN (BJT) (ej. 2N2222, BC547) |
| D1 | 1 | LED Rojo |
| R3 | 1 | Resistor de 330 Ω |
| P1 | 1 | Fuente de alimentación 5V, 5A |

## Descripción del Circuito

### Cómo Funciona

El circuito funciona como un **interruptor automático activado por oscuridad**. La fotorresistencia y el resistor forman un divisor de voltaje que controla la base del transistor.

#### Principio de Operación

**Cuando hay LUZ (día):**
- La fotorresistencia (R1) tiene **baja resistencia** (pocos cientos de ohmios)
- La mayor parte del voltaje cae en R2 (10 kΩ)
- El voltaje en la base del transistor es **BAJO** (insuficiente para activarlo)
- El transistor está en **corte** (apagado)
- El LED rojo está **APAGADO**

**Cuando hay OSCURIDAD (noche):**
- La fotorresistencia (R1) tiene **alta resistencia** (varios kΩ o MΩ)
- La mayor parte del voltaje cae en R1
- El voltaje en la base del transistor es **ALTO** (suficiente para activarlo)
- El transistor entra en **saturación** (encendido)
- El LED rojo está **ENCENDIDO**

### Función de los Componentes

- **R1 (Fotorresistencia/LDR)**: Sensor que varía su resistencia según la luz ambiente
  - Con luz: ~100-1000 Ω
  - Sin luz: ~1 MΩ o más
  
- **R2 (10 kΩ)**: Forma un divisor de voltaje con la fotorresistencia y limita la corriente de base del transistor

- **T1 (Transistor NPN)**: Actúa como interruptor controlado por voltaje
  - Cuando Vbe > 0.7V se activa
  - Controla el flujo de corriente hacia el LED

- **R3 (330 Ω)**: Resistor limitador de corriente para proteger el LED
  - Limita la corriente a aproximadamente 12-15 mA

- **D1 (LED Rojo)**: Indicador visual que se enciende en la oscuridad

## Diagrama de Funcionamiento

| Condición de Luz | Resistencia R1 | Voltaje Base | Estado Transistor | LED |
|------------------|----------------|--------------|-------------------|-----|
| Mucha luz (día) | Baja (~100 Ω) | Bajo (<0.7V) | Apagado (corte) | Apagado |
| Poca luz (atardecer) | Media (~10 kΩ) | Medio (~0.7V) | Activándose | Tenue |
| Oscuridad (noche) | Alta (>100 kΩ) | Alto (>0.7V) | Encendido (saturación) | Encendido |

## Aplicaciones Prácticas

Este circuito es útil para:
1. **Luz nocturna automática**: Se enciende cuando oscurece
2. **Sistema de iluminación de emergencia**: Activa luces cuando se va la electricidad (y la luz ambiente)
3. **Detector de sombras**: Responde cuando un objeto bloquea la luz
4. **Proyecto educativo**: Demuestra el uso de sensores analógicos con transistores

## Ajustes y Modificaciones

### Ajustar la Sensibilidad
- **Aumentar R2**: El LED se encenderá con más luz (menos sensible)
- **Disminuir R2**: El LED se encenderá solo en mayor oscuridad (más sensible)
- Valores típicos: 4.7 kΩ a 22 kΩ

### Cambiar el LED por Otros Dispositivos
- Se puede reemplazar el LED + R3 por:
  - Un relé (con diodo de protección)
  - Un buzzer
  - Otro transistor para controlar cargas mayores

## Notas de Construcción

- **Polaridad del LED**: Ánodo (pata larga) hacia el colector del transistor a través de R3
- **Conexión del Transistor NPN**:
  - **Colector (C)**: Conectado a R3 y LED
  - **Base (B)**: Conectado al punto medio del divisor R1-R2
  - **Emisor (E)**: Conectado a tierra (GND)
- Coloque la fotorresistencia donde pueda recibir luz ambiente
- El circuito responde en aproximadamente 1 segundo a cambios de luz

## Alimentación

- **Voltaje**: 5V DC
- **Consumo**: 
  - Con LED apagado: <1 mA
  - Con LED encendido: ~15 mA
- Conecte P1+ a la línea positiva y P1- a GND

## Principio Físico

La fotorresistencia está hecha de material semiconductor (sulfuro de cadmio, CdS) que cambia su conductividad según la luz incidente. Los fotones liberan electrones, reduciendo la resistencia del material cuando está iluminado.