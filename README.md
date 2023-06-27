<html>
<head>
</head>
<body>
  <h1 align="center">Моделирование процесса выделения памяти и отображение результата в QChart</h1>
  <h2>Задача</h2>
  <p align="justify">Необходимо провести моделирование процесса выделения памяти под совокупность задач. Каждая задача представляется следующими атрибутами: имя, размер (в байтах), время начала выполнения   задачи, длительность. Совокупность задач образует очередь задач. В ходе работы (моделирования) формируется также очередь выполняемых задач (находящихся в памяти в данный момент времени) ; список задач, для   которых время начала выполнения истекло (отказ в выделении памяти); список выполненных (завершенных) задач. На входе пользователь задает объем памяти (в байтах), список задач с соответствующими атрибутами. На выходе необходимо отобразить список всех задач; список задач, загруженных в память в данный момент времени; список задач, не загруженных вовремя в память; список отработавших задач; карту памяти (например, memo-поле из нулей и единиц, где 0 - свободный байт, 1 - занятый байт).</p>
  <p align="justify">При работе с битовым массивом память разделяется на единичные блоки размещения размером от нескольких слов до нескольких килобайт. В битовой карте каждому свободному блоку соответствует один бит, равный нулю, а каждому занятому блоку – бит, установленный в 1. Битовый массив представляет простой способ отслеживания слов в памяти фиксированного объема, потому что размер битовой карты зависит только от размеров памяти и единичного блока. Основная проблема, возникающая при использовании данной схемы, заключается в том, что при решении переместить k-блочный процесс в память модуль управления памяти должен найти в битовой карте серию из k следующих друг за другом нулевых битов.</p>
<h2>Ввод данных</h2>
<ul>
  <li>Размер выделяемой памяти ограничивается значениями от 1 до 20 байт включительно</li>
  <li>Название процесса можно давать как на русском, так и на английском с пробелами</li>
  <li>Время до начала процесса никак не ограничивается, принимается целое действительное число</li>
  <li>Продолжительность ограничивается минимальным значением 1 (секунда)</li>
</ul>
<h2>Пример работы</h2>
<img src="https://res.cloudinary.com/ded6c9rmz/image/upload/v1687893615/Photo%20readme/1_phcfht.png" alt="Главное окно">
<img src="https://res.cloudinary.com/ded6c9rmz/image/upload/v1687893615/Photo%20readme/2_rjjjty.png" alt="Графики QChart">  
</body>
</html>