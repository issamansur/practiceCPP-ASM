# practiceCPP-ASM

[cpucommands]: 
### Команды процессора:
- [Префиксы] [Оператор] [Операнды] [Режим адресации] [Префикс команды]
- Состоят из одного-нескольких байт (чем меньше - тем быстрее)
  - Первый байт указывает на **кол-во читаемых байтов** процессором
    <hr>
  - **Код операции**, выполняемый процессором
    <hr>
  - [**Операнды**][#operands], с которыми выполняется операция
    - Операнды - это **коды данных**, с которыми проводятся операции (**входные** и **выходные**)
    - Могут быть **регистрами**, **константами** или **адресами в памяти**
    - Располагаются:
      - во **внутренних регистрах** - удобно, но **недостаточно места**
      - в **ячейках памяти** - часто и удобно - в массивах
      - в **устр-ах ввода/вывода** - редко, при обмене с внешн. устройствами
    - **Адресация операндов** указывает процессору на расположение операндов
    <hr>
- Преобразуются процессором в последовательность **внутренних команд**
    
### Операнды <a name="tith"></a>
123
