# Semáforo con Pulsador usando Arduino

## Descripción General
Este proyecto implementa un **semáforo interactivo controlado por pulsador** usando Arduino. Al presionar el botón, se inicia una secuencia de cambio de luces similar a un semáforo real: verde → amarillo → rojo. Es ideal para aprender programación básica de Arduino, control de salidas digitales y lectura de entradas.

## Componentes Requeridos

| Componente | Cantidad | Especificación |
|-----------|----------|---------------|
| U1 | 1 | Arduino Uno R3 |
| D1 | 1 | LED Rojo |
| D2 | 1 | LED Amarillo |
| D3 | 1 | LED Verde |
| R1, R2, R3 | 3 | Resistores de 220 Ω (para LEDs) |
| S1 | 1 | Pulsador (pushbutton) |
| R4 | 1 | Resistor de 10 kΩ (pull-down) |
| - | - | Cables de conexión |
| - | - | Protoboard |

## Descripción del Circuito

### Cómo Funciona

El Arduino monitorea constantemente el estado del pulsador. Cuando detecta que el botón fue presionado (señal HIGH), ejecuta una secuencia de semáforo:

1. **Verde** encendido por 2 segundos (paso libre)
2. **Amarillo** encendido por 1 segundo (precaución)
3. **Rojo** encendido por 2 segundos (alto)
4. Vuelve al estado inicial esperando otra pulsación

### Conexiones del Circuito

#### LEDs (Salidas Digitales)
- **LED Verde (D3)**: 
  - Pin 10 → Resistor 220Ω (R3) → Ánodo LED → Cátodo LED → GND
- **LED Amarillo (D2)**: 
  - Pin 9 → Resistor 220Ω (R2) → Ánodo LED → Cátodo LED → GND
- **LED Rojo (D1)**: 
  - Pin 8 → Resistor 220Ω (R1) → Ánodo LED → Cátodo LED → GND

#### Pulsador (Entrada Digital)
- **Terminal 1**: Conectado a 5V del Arduino
- **Terminal 2**: Conectado al Pin 2 del Arduino
- **Resistor Pull-down (R4)**: Pin 2 → 10kΩ → GND
  - Mantiene la entrada en LOW cuando el botón no está presionado

## Código Arduino

```cpp
const int ledRojo = 8;
const int ledAmarillo = 9;
const int ledVerde = 10;
const int boton = 2;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(boton, INPUT);
}

void loop() {
  if (digitalRead(boton) == HIGH) {
    // LED Verde - Paso libre
    digitalWrite(ledVerde, HIGH);
    delay(2000);  // 2 segundos
    digitalWrite(ledVerde, LOW);
    
    // LED Amarillo - Precaución
    digitalWrite(ledAmarillo, HIGH);
    delay(1000);  // 1 segundo
    digitalWrite(ledAmarillo, LOW);
    
    // LED Rojo - Alto/Detención
    digitalWrite(ledRojo, HIGH);
    delay(2000);  // 2 segundos
    digitalWrite(ledRojo, LOW);
  }
}
```

## Explicación del Código

### Declaración de Variables
```cpp
const int ledRojo = 8;
const int ledAmarillo = 9;
const int ledVerde = 10;
const int boton = 2;
```
- Define constantes para los pines utilizados
- Facilita la lectura y modificación del código

### Función `setup()`
```cpp
void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(boton, INPUT);
}
```
- Se ejecuta **una sola vez** al iniciar el Arduino
- Configura los pines de los LEDs como salidas (`OUTPUT`)
- Configura el pin del botón como entrada (`INPUT`)

### Función `loop()`
```cpp
void loop() {
  if (digitalRead(boton) == HIGH) {
    // Secuencia del semáforo
  }
}
```
- Se ejecuta **continuamente** en bucle
- Lee el estado del botón con `digitalRead()`
- Solo ejecuta la secuencia cuando detecta `HIGH` (botón presionado)

### Secuencia de Semáforo

**Verde (2 segundos):**
```cpp
digitalWrite(ledVerde, HIGH);  // Enciende
delay(2000);                    // Espera 2000ms
digitalWrite(ledVerde, LOW);   // Apaga
```

**Amarillo (1 segundo):**
```cpp
digitalWrite(ledAmarillo, HIGH);
delay(1000);
digitalWrite(ledAmarillo, LOW);
```

**Rojo (2 segundos):**
```cpp
digitalWrite(ledRojo, HIGH);
delay(2000);
digitalWrite(ledRojo, LOW);
```

## Diagrama de Tiempos

```
Botón presionado ↓
                  |
Verde:    ████████████████      (2s)
Amarillo:                 ████████  (1s)
Rojo:                            ████████████████  (2s)
                                                |
                              Secuencia completa (5s total)
```

## Funcionamiento Paso a Paso

1. **Estado inicial**: Todos los LEDs apagados, esperando pulsación
2. **Usuario presiona botón**: Arduino detecta señal HIGH en pin 2
3. **Verde enciende**: Permanece 2 segundos, luego se apaga
4. **Amarillo enciende**: Permanece 1 segundo, luego se apaga
5. **Rojo enciende**: Permanece 2 segundos, luego se apaga
6. **Vuelve al estado inicial**: Esperando nueva pulsación

**Duración total de la secuencia:** 5 segundos

## Función de los Componentes

### Arduino Uno R3
- **Microcontrolador**: ATmega328P
- **Pines digitales**: 14 (0-13), usamos 2, 8, 9 y 10
- **Voltaje de operación**: 5V
- **Alimentación**: USB o adaptador 7-12V

### Resistores de 220Ω (R1, R2, R3)
- Limitan la corriente a través de los LEDs
- Corriente LED: (5V - 2V) / 220Ω ≈ 13.6 mA
- Protegen tanto al LED como al pin del Arduino

### Resistor de 10kΩ (R4)
- **Pull-down resistor**: Mantiene el pin 2 en estado LOW cuando el botón no está presionado
- Sin este resistor, el pin quedaría "flotante" y daría lecturas erróneas
- Cuando se presiona el botón, el pin recibe 5V (HIGH)

### LEDs
- **Rojo (D1)**: Indica detención
- **Amarillo (D2)**: Indica precaución
- **Verde (D3)**: Indica paso libre
- Voltaje directo típico: 2-2.2V
- Corriente nominal: 20 mA

### Pulsador (S1)
- Interruptor momentáneo normalmente abierto (NO)
- Al presionar conecta 5V al pin 2
- Al soltar, R4 lleva el pin a GND (LOW)

## Diagrama de Conexiones

```
Arduino Pin 8  ──→ R1 (220Ω) ──→ LED Rojo ──→ GND
Arduino Pin 9  ──→ R2 (220Ω) ──→ LED Amarillo ──→ GND
Arduino Pin 10 ──→ R3 (220Ω) ──→ LED Verde ──→ GND

Arduino 5V ──→ Pulsador ──┬──→ Pin 2
                          │
                          └──→ R4 (10kΩ) ──→ GND
```

## Mejoras y Modificaciones

### 1. Evitar Rebote del Botón (Debouncing)
El código actual puede activar múltiples veces por una sola pulsación debido al rebote mecánico:

```cpp
void loop() {
  if (digitalRead(boton) == HIGH) {
    delay(50);  // Anti-rebote
    if (digitalRead(boton) == HIGH) {
      // Secuencia del semáforo
      while(digitalRead(boton) == HIGH);  // Espera a que suelte
      delay(50);  // Anti-rebote al soltar
    }
  }
}
```

### 2. Semáforo Cíclico Automático
Hacer que el semáforo cambie automáticamente sin necesidad de presionar:

```cpp
void loop() {
  // Verde
  digitalWrite(ledVerde, HIGH);
  delay(5000);
  digitalWrite(ledVerde, LOW);
  
  // Amarillo
  digitalWrite(ledAmarillo, HIGH);
  delay(2000);
  digitalWrite(ledAmarillo, LOW);
  
  // Rojo
  digitalWrite(ledRojo, HIGH);
  delay(5000);
  digitalWrite(ledRojo, LOW);
  
  // Amarillo antes de verde
  digitalWrite(ledAmarillo, HIGH);
  delay(2000);
  digitalWrite(ledAmarillo, LOW);
}
```

### 3. Contador de Tiempo en Monitor Serial
Mostrar el estado actual en el monitor serial:

```cpp
void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(boton) == HIGH) {
    Serial.println("¡Semáforo activado!");
    
    Serial.println("Verde - Puede pasar");
    digitalWrite(ledVerde, HIGH);
    delay(2000);
    digitalWrite(ledVerde, LOW);
    
    Serial.println("Amarillo - Precaución");
    digitalWrite(ledAmarillo, HIGH);
    delay(1000);
    digitalWrite(ledAmarillo, LOW);
    
    Serial.println("Rojo - Alto");
    digitalWrite(ledRojo, HIGH);
    delay(2000);
    digitalWrite(ledRojo, LOW);
    
    Serial.println("Secuencia completada\n");
  }
}
```

### 4. Semáforo Peatonal Doble
Agregar un segundo conjunto de LEDs para simular cruce peatonal:

```cpp
const int ledRojoAuto = 8;
const int ledVerdeAuto = 9;
const int ledRojoPeaton = 11;
const int ledVerdePeaton = 12;

void loop() {
  if (digitalRead(boton) == HIGH) {
    // Autos en verde, peatones en rojo
    digitalWrite(ledVerdeAuto, HIGH);
    digitalWrite(ledRojoPeaton, HIGH);
    delay(5000);
    
    // Cambio: autos a rojo, peatones a verde
    digitalWrite(ledVerdeAuto, LOW);
    digitalWrite(ledRojoAuto, HIGH);
    digitalWrite(ledRojoPeaton, LOW);
    digitalWrite(ledVerdePeaton, HIGH);
    delay(3000);
    
    // Parpadeo verde peatonal (advertencia)
    for(int i=0; i<5; i++) {
      digitalWrite(ledVerdePeaton, LOW);
      delay(300);
      digitalWrite(ledVerdePeaton, HIGH);
      delay(300);
    }
    
    // Volver a estado inicial
    digitalWrite(ledVerdePeaton, LOW);
    digitalWrite(ledRojoPeaton, HIGH);
    digitalWrite(ledRojoAuto, LOW);
  }
}
```

### 5. Ajustar Tiempos de Secuencia
Modificar los valores de `delay()` según necesidad:

```cpp
const int TIEMPO_VERDE = 3000;     // 3 segundos
const int TIEMPO_AMARILLO = 1500;  // 1.5 segundos
const int TIEMPO_ROJO = 4000;      // 4 segundos
```

## Aplicaciones Prácticas

Este proyecto es útil para:

1. **Educación vial**: Enseñar funcionamiento de semáforos a niños
2. **Maquetas**: Controlar semáforos en maquetas de ciudades
3. **Aprendizaje Arduino**: Primer proyecto con entradas y salidas digitales
4. **Control de procesos**: Base para sistemas de señalización industrial
5. **Juegos educativos**: Integrar en juegos de "luz roja, luz verde"

## Solución de Problemas

| Problema | Posible Causa | Solución |
|----------|---------------|----------|
| LEDs no encienden | Polaridad invertida | Verificar ánodo (+) y cátodo (-) |
| LED muy tenue | Resistor muy alto | Usar 220Ω o menor |
| Botón no funciona | Falta pull-down | Verificar R4 (10kΩ) a GND |
| Secuencia no inicia | Pin incorrecto | Verificar conexión al pin 2 |
| Arduino no responde | Código no cargado | Subir código nuevamente |
| LEDs quedan encendidos | Error en código | Verificar `digitalWrite(LED, LOW)` |

## Expansiones Avanzadas

### Con Sensor Ultrasónico
Activar el semáforo cuando detecta un vehículo:
```cpp
const int trigPin = 7;
const int echoPin = 6;

// En loop, reemplazar lectura de botón por:
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034 / 2;

if (distance < 20) {  // Objeto a menos de 20cm
  // Iniciar secuencia
}
```

### Con Pantalla LCD
Mostrar el color actual y tiempo restante en LCD 16x2.

### Con Comunicación Bluetooth
Controlar el semáforo desde smartphone vía módulo HC-05.

## Recursos de Aprendizaje

- **Documentación Arduino**: https://www.arduino.cc/reference/
- **digitalRead()**: Lee estado HIGH o LOW de un pin
- **digitalWrite()**: Escribe HIGH o LOW en un pin
- **delay()**: Pausa el programa en milisegundos
- **pinMode()**: Configura pin como INPUT o OUTPUT

## Consumo de Energía

- **Arduino Uno**: ~50 mA (sin carga)
- **Cada LED**: ~14 mA
- **Total máximo**: ~92 mA (todos encendidos simultáneamente)
- **Alimentación USB**: 5V, suficiente para este proyecto

## Notas Importantes

✓ **Verificar polaridad de LEDs**: Pata larga = ánodo (+)  
✓ **No omitir resistores**: Protegen LEDs y Arduino  
✓ **Pull-down necesario**: R4 evita lecturas erróneas  
✓ **Código simple**: Ideal para principiantes  
✓ **Secuencia bloqueante**: El Arduino no puede hacer otras tareas durante los delays

---

**Este proyecto es perfecto como introducción a Arduino, enseñando conceptos fundamentales de programación, electrónica digital y control de dispositivos externos.**