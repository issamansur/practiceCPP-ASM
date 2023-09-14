# Практика по С+++ (С++ + ASM)
## Содержание:
1. [Команды процессора](#commands)
2. [Операнды](#operands)
3. [Адресация слов и байтов](#addresses)
4. [Сегментирование](#segments)
 
## Команды процессора <a name="commands"></a>
- [Префиксы] [Оператор] [Операнды] [Режим адресации] [Префикс команды]
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


