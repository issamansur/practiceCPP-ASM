# Практика по С+++ (С++ + ASM)
## Содержание:
1. [Команды процессора](#commands)
2. [Операнды](#operands)
3. [Адресация слов и байтов](#addresses)
4. [Сегментирование](#segments)
5. [Основные группы команд процессора](#main-commands)
6. [Прерывания](#interrupts) 
 
## Команды процессора <a name="commands"></a>
- [Префиксы] [Оператор] [Операнды] [Режим адресации] [Префикс команды]
- ![image](https://github.com/issamansur/practiceCPP-ASM/assets/77580844/54b3e90b-8352-488b-90e1-7643f8cb31b4)
- Состоят из одного-нескольких байт (чем меньше - тем быстрее)
  - Первый байт указывает на **кол-во читаемых байтов** процессором
  - **Код операции**, выполняемый процессором
  - [**Операнды**](#operands), с которыми выполняется операция
- Преобразуются процессором в последовательность **внутренних команд**
    
## Операнды <a name="operands"></a>
- Операнды - это **коды данных**, с которыми проводятся операции (**входные** и **выходные**)
- Могут быть **регистрами**, **константами** или **адресами в памяти**
- Располагаются:
  - во **внутренних регистрах** - удобно, но **недостаточно места**
  - в **ячейках памяти** - часто и удобно - в массивах
  - в **устр-ах ввода/вывода** - редко, при обмене с внешн. устройствами
- **Адресация операндов** указывает процессору на расположение операндов:
  - 1.1. **Непосредственная** адресация - |в памяти под программу| хранится сам операнд (значение)
  - 1.2. **Прямая/абсолютная** адресация - |в памяти под программу| хранится адрес(ссылка) на сам операнд в |данных| 
  - ![image](https://github.com/issamansur/practiceCPP-ASM/assets/77580844/17f2b4ab-d8c0-40d2-b92c-4dbb88f6ed00)
  - ![image](https://github.com/issamansur/practiceCPP-ASM/assets/77580844/0c5e796c-8eda-4c98-ad35-304b677cd290)
- После выполнения операции **содержимое регистра меняется** в зависимости от типа адресации:
  - 2.1. **автоинкрементная** адресация - увеличивается на 1-2
  - 2.2. **автодекрементная** адресация - уменьшается на 1-2
  - 2.3. **буфер типа LIFO** (например, в стеке) - оба типа используются.

## Адресация слов и байтов <a name="addresses"></a>
- Слово имеет четный адрес (0, 2, 4, ..., 2n)
- Слово состоит из двух байтов (16 битов):
  - **Старший байт** (первые 8 бит) имеет **нечётный адрес** (1, 3, 5, ..., 2n-1)
  - **Младший байт** (вторые 8 бит) имеет **чётный адрес** (0, 2, 4, ..., 2n) - совпадает с байтом слова
  - ![image](https://github.com/issamansur/practiceCPP-ASM/assets/77580844/05046e3e-aaf5-4006-8e50-9bd70e474976)

## Сегментирование <a name="segments"></a>
- Память разбивается на **сегменты**
- Сегмент состоит из:
  - **Адрес** сегмента (первый байт сегмента) (начало)
  - **Размер** сегмента (10 000 байт = 64 Кбайт)
  - **Смещение** - сдвиг от адреса (начала) указывает на какой-либо **физический адрес**
  - ![image](https://github.com/issamansur/practiceCPP-ASM/assets/77580844/259709e3-4d62-4489-a8e0-8abcbf1cf7f7)
  - ![image](https://github.com/issamansur/practiceCPP-ASM/assets/77580844/d60ae61d-dcb5-42ab-bd57-81979eb3c015)

## Основные группы команд процессора <a name="main-commands"></a>
- Команды **пересылки данных**:
  - Данные пересылаются/копируются между **памятью**, **регистрами процессора** и **УВВ** (устройством ввода и вывода)
  - **Не требуют** выполнения операций **над данными**
    1. **Загрузка/запись** содержимого **во** внутренние **регистры** процессора
    2. **Сохранение** **в памяти/стеке** содержимого внутренних регистров процессора
    3. **Копирование** содержимого из одной области памяти в другую
    4. **Запись в УВВ** и **чтение из УВВ**
    5. **Обмен** информацией **между регистром** и **регистром или памятью**
    6. **Обмен** информацией **между байтами регистра или памяти**
- **Арифметические** команды:
  - Параметры: **1-2 входных**, **1 выходной**
    1. Команды операций **с фикс. запятой** - знак любой
    2. Команды операций **с плав. запятой** - операнды в 2+ ячейках памяти
    3. Команды **очистки** - быстрее пересылки. возоможно логическая
    4. Команды **(инк-/де-)кремента** +=1 / -=1
    5. Команды **сравнения** - формирует флаги результата на основании сравнения операндов
- **Логические** команды (выполняются **побитово**):
  - Параметры: **1-2 входных**, **1 выходной**
    1. Логические **И, ИЛИ, ИСКЛ. ИЛИ, побитная инверсия по маске**
    2. Лог., арифм., цикл. **сдвиги** - вправо или влево, с разными значениями вдвигаемых битов
    3. **Проверка** битов и операндов - устанавливает флаги состояния
    4. **Установка и очистка** битов/флагов регистра состояния процессора (PSW) - для принудительного перевода процессора в какой-либо режим 
- Команды **переходов**:
  - Нет операндов
  - Изменение регистров счётчиков команд
  - Вызов подпрограмм, ветвление алгоритмов
  1. **Безусловные** - ...
  2. **Условные** - в зависимости от значений флагов регистра состояния процессора:
    - если **0 / 1**
    - если **есть/нет** переполнение
    - если **> 0, < 0, >= 0, <= 0**
    - т. д.
  3. Переход **с возвратом в исходную точку** - **[ПРЕРЫВАНИЯ](#interrupts)**
  4. Проверка условий **через команду сравнению**
- ![image](https://github.com/issamansur/practiceCPP-ASM/assets/77580844/8c939897-328e-4890-881a-884edcb5a05e)

### Прерывания <a name="interrupts"></a>

| Vector | AH  | Description                               |
|--------|---- |-------------------------------------------|
| 05h    |    | Executed when Shift-Print screen is pressed, as well as when the BOUND instruction detects a bound failure. |
| 08h    |    | Real-time clock interrupt. Fires 18.2 times/second. BIOS increments the time-of-day counter during this interrupt. |
| 09h    |    | Keyboard interrupt, generally triggered when a key on a keyboard is pressed. |
| 10h    | 00h | Set Video Mode                           |
| -      | 01h | Set Cursor Shape                         |
| -      | 02h | Set Cursor Position                      |
| -      | 03h | Get Cursor Position And Shape            |
| -      | 04h | Get Light Pen Position                   |
| -      | 05h | Set Display Page                         |
| -      | 06h | Clear/Scroll Screen Up                   |
| -      | 07h | Clear/Scroll Screen Down                 |
| -      | 08h | Read Character and Attribute at Cursor   |
| -      | 09h | Write Character and Attribute at Cursor  |
| -      | 0Ah | Write Character at Cursor                |
| -      | 0Bh | Set Border Color                         |
| -      | 0Ch | Write Graphics Pixel                     |
| -      | 0Dh | Read Graphics Pixel                      |
| -      | 0Eh | Write Character in TTY Mode              |
| -      | 0Fh | Get Video Mode                           |
| -      | 10h | Set Palette Registers (EGA, VGA, SVGA)   |
| -      | 11h | Character Generator (EGA, VGA, SVGA)     |
| -      | 12h | Alternate Select Functions (EGA, VGA, SVGA) |
| -      | 13h | Write String                             |
| -      | 1Ah | Get or Set Display Combination Code (VGA, SVGA) |
| -      | 1Bh | Get Functionality Information (VGA, SVGA) |
| -      | 1Ch | Save or Restore Video State (VGA, SVGA)  |
| -      | 4Fh | VESA BIOS Extension Functions (SVGA)     |
| 11h    |    | Returns equipment list                   |
| 12h    |    | Return conventional memory size          |
| 13h    |    | Low-Level Disk Services                  |
| -      | 00h | Reset Disk Drives                        |
| -      | 01h | Check Drive Status                       |
| -      | 02h | Read Sectors                             |
| -      | 03h | Write Sectors                            |
| -      | 04h | Verify Sectors                           |
| -      | 05h | Format Track                             |
| -      | 08h | Get Drive Parameters                     |
| -      | 09h | Init Fixed Drive Parameters               |
| -      | 0Ch | Seek To Specified Track                   |
| -      | 0Dh | Reset Fixed Disk Controller               |
| -      | 15h | Get Drive Type                           |
| -      | 16h | Get Floppy Drive Media Change Status     |
| -      | 17h | Set Disk Type                            |
| -      | 18h | Set Floppy Drive Media Type              |
| -      | 41h | Extended Disk Drive (EDD) Installation Check |
| -      | 42h | Extended Read Sectors                    |
| -      | 43h | Extended Write Sectors                   |
| -      | 44h | Extended Verify Sectors                  |
| -      | 45h | Lock/Unlock Drive                        |
| -      | 46h | Eject Media                             |
| -      | 47h | Extended Seek                           |
| -      | 48h | Extended Get Drive Parameters            |
| -      | 49h | Extended Get Media Change Status         |
| -      | 4Eh | Extended Set Hardware Configuration       |
| 14h    |    | Serial Port Services                      |
| -      | 00h | Serial Port Initialization                |
| -      | 01h | Transmit Character                       |
| -      | 02h | Receive Character                        |
| -      | 03h | Status                                   |
| 16h    |    | Keyboard Services                         |
| -      | 00h | Read Character                            |
| -      | 01h | Read Input Status                         |
| -      | 02h | Read Keyboard Shift Status                |
| -      | 05h | Store Keystroke in Keyboard Buffer        |
| -      | 10h | Read Character Extended                   |
| -

      | 11h | Read Input Status Extended                |
| -      | 12h | Read Keyboard Shift Status Extended       |
| 17h    |    | Printer Services                          |
| -      | 00h | Print Character to Printer                |
| -      | 01h | Initialize Printer                        |
| -      | 02h | Check Printer Status                      |
| 18h    |    | Execute Cassette BASIC                    |
| 19h    |    | After POST, used by the BIOS to load the operating system. Can be called to reboot the computer. |
| 1Ah    | 00h | Real-Time Clock Services                   |
| -      | 01h | Set RTC                                  |
| -      | 02h | Read RTC Time                            |
| -      | 03h | Set RTC Time                            |
| -      | 04h | Read RTC Date                            |
| -      | 05h | Set RTC Date                            |
| -      | 06h | Set RTC Alarm                            |
| -      | 07h | Reset RTC Alarm                          |

| AH    | Service                         | Description                              |
|-------|---------------------------------|------------------------------------------|
| 00h   | Tape drive                      | Turn on tape drive motor                 |
| 01h   | Tape drive                      | Turn off tape drive motor                |
| 02h   | Tape drive                      | Read data                                |
| 03h   | Tape drive                      | Write data                               |
| 09h   | SYSTEM                          | Error reporting data during POST         |
| 52h   | INT 13h extensions              | Intercept when media is ejected         |
| 84h   | Joystick                        | Joystick functions                       |
| 85h   | SYSTEM                          | Intercept keystroke PetSis               |
| 86h   | BIOS                            | Wait microsecond interval                |
| 87h   | SYSTEM                          | Copy extended memory                     |
| 88h   | SYSTEM                          | Get extended memory size                 |
| 89h   | SYSTEM                          | Go to protected mode                     |
| 2400h | SYSTEM                          | Deactivate line A20                      |
| 2401h | SYSTEM                          | Activate line A20                        |
| 5300h | APM                             | Check installation                       |
| 5301h | APM                             | Connect real mode interface              |
| 5302h | APM                             | Connect 16-bit interface                 |
| 5303h | APM                             | Connect 32-bit interface                 |
| 5304h | APM                             | Disconnect interface                     |
| 5307h | APM                             | Set power state                          |
| 5307h | APM                             | CX=0001h - Pasar pc a modo STANBY        |
| 5307h | APM                             | CX=0002h - Suspend system               |
| 5307h | APM                             | CX=0003h - Erase system                 |
| 5308h | APM                             | Enable / disable power management        |
| 5380h | APM                             | BH=04h - Get auto off time               |
| 5380h | APM                             | BH=05h - Set auto off time               |
| 5380h | APM                             | BH=0Ch - Get CPU speed mode              |
| 5380h | APM                             | BH=0Dh - Set CPU speed mode              |
| C1h   | SYSTEM                          | Get Extended BIOS Data Segment Boot     |
| C200h | PS / 2 mouse                   | Enable / Disable mouse                   |
| C201h | PS / 2 mouse                   | Restart mouse                            |
| C202h | PS / 2 mouse                   | Set sample rate                          |
| C203h | PS / 2 mouse                   | Set resolution                           |
| C204h | PS / 2 mouse                   | Get type                                 |
| C205h | PS / 2 mouse                   | Initialize mouse                         |
| C206h | PS / 2 mouse                   | Extended commands                        |
| C207h | PS / 2 mouse                   | Set mouse driver address                 |
| C208h | PS / 2 mouse                   | Write to mouse port                      |
| C209h | PS / 2 mouse                   | Read from mouse port                     |
|-------| Joystick function table         |                                          |
| 00h   | Joystick                        | Read the four buttons on the joystick   |
| 01h   | Joystick                        | Read the lever                           |
| 02h   | Joystick                        | Same as 00h but in values from 0 to 255  |
| 03h   | Joystick                        | Calibrate the joystick                   |
| 04h   | Joystick                        | Check if the joystick is calibrated     |
| 05h   | Joystick                        | Read raw data of the lever               |
| 08h   | Joystick                        | Read the specified button                |
| 09h   | Joystick                        | Read all buttons up to button 16         |
| 80h   | Joystick                        | Remove the driver from memory            |
| 81h   | Joystick                        | Check if the driver is in memory         |

Обратите внимание, что некоторые службы прерывания INT 15h специфичны для определенных контекстов и функций (например, APM для управления энергосбережением и PS/2 mouse для управления мышью).
