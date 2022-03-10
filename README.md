#### Конвейер:

**ССЫЛКА НА ДАННЫЕ**

### https://drive.google.com/drive/folders/15oYcZGL_gt97Dsn4MZrojE7idIwWKGWA

Тут данные для 2 физ листов(2 папки): 

-G4EmStandardPhysics
-G4EmStandardPhysics_option4


## 1.  Длины взаимодействий  (про разные длины - разные статьи: 1.1, 1.2, ... aka "Конвейер") (Публикации Q2, аналогично Oreshkin comment)

### 1.1 **Про гамма:**

Поиск спектра RREA гаммы в источниках и оценка спектра из спектра RREA и Geant4
Посчитанная на GEANT4 длина взаимодействия для разных точек при разных плотностях воздуха и полях на спектре энергии гамма (длина затухания, разворот, рождение убегающих электронов, позитронов)
Фиттинг и//или аналитический вывод этой же зависимости
Позитроны
Комментарий о скалируемости

### 1.2 :**Про RREA::**

Расчёт на Geant4 длины нарастания RREA при различных полях и плотностях воздуха
Сравнение с формулой Гуревича, Лехтинена и, главное, эмпирической формулы Дваера
Получение с помощью фита своей эмпирической формулы
Вывод формулы исходя из стационарного спектра RREA

### 1.3 **Разворот электронов и позитронов:**

Моделирование на Geant4 при различных параметрах (в том числе и стартовый угол частицы), аналогично моделированию Тимура
Учёт спектра рождаемых до разворота электронов, позитронов.
Получение эмпирической формулы для вероятности разворота P(θ,E,ρ)

### 1.4 **Динамика позитронов**

Моделирование на Geant4.
Длина аннигиляции позитронов с учётом их спектра.
Длина рождения убегающих электронов.
Длина рождения гаммы.
Получение эмпирических формул.

### 1.5 **Диаграмма направленности излучения гаммы одной ячейкой**

### 1.6 **Влияние начальной энергии seed электрона на количество лавин убегающих электронов**

К вопросу о влиянии стартовой энергии seed электрона на параметры рождаемой им лавины можно подойти следующим образом.
Что мы знаем? Мы знаем, что если лавина пройдёт расстояние много большее длины нарастания, то она станет стационарной. То есть в ней будет устойчивый рост количества частиц и устойчивый спектр убегающих электронов. Это означает, что на таких масштабах все лавины одинаковые.
Но от энергии начального электрона действительно количество частиц зависит. Почему?
Что мы знаем? Мы знаем, что чем выше энергия у электрона, тем больше убегающих электронов в начале ячейки он может родить, не убившись. То есть электрон с маленькой энергией может вообще затухнуть. Со средней может родить самую обычную лавину. А с большой энергией в силу большого количества рождаемых им убегающих электронов в начале ячейки может родить большую лавину, пропорциональную количеству этих рождённых в начале электронов.
Как это всё можно разгрести? Как можно подойти к вопросу о влиянии начальной энергии, если все лавины одинаковые, но зависимость от seed есть?
Я предлагаю следующий логический трюк. Давайте считать что от начальной энергии электрона зависят не параметры лавины убегающих электронов, а количество лавин убегающих электронов, которые он рождает. Так можно подумать, исходя из соображений о влиянии большой энергии выше.
Что этот трюк даст? Это даёт инструмент для последовательного изучения вопроса о влиянии энергии seed электрона, а также может дать простые в использовании формулы в дальнейшем. И мы избавляемся от логических противоречий. У нас лавины остаются одинаковыми, что очень упрощает теоретические модели. Но при этом мы получаем зависимость от начальной энергии электрона, которую в такой форме легко учитывать.
Теперь следующий вопрос: как это посчитать?
Берёте длинную ячейку (длинную по сравнению с длиной нарастания лавины) с фиксированным полем и фиксированной плотностью. И запускаете seed электроны в начале ячейки. Ставите в конце ячейки детектор или ещё каким-нибудь образом подсчитываете суммарное количество убегающих электронов, которые рождаются в результате попадания seed в ячейку. И строите зависимость количества убегающих электронов от seed.
Далее нужно понять, какое число электронов соответствуют ровно одной лавине. Скорее всего, из первой симуляции на усреднённых данных этого видно не будет, хотя может быть в зависимости будет некоторая особая точка, где характер зависимости меняется. Если будет особая точка, то ей будет соответствовать та энергия, при которой рождается ровно одна лавина. Потому что при меньших энергиях лавина либо родится, либо не родится. А при больших энергиях либо одна лавина родится, либо много.
Но если такой особенности нет, то можно пойти по другому пути. Берёте теперь фиксированную какую-нибудь энергию seed и смотрите на распределение количества рождаемых этой энергией убегающих электронов. В этой зависимости должны быть ярко выделенные пики, соответствующие определённому числу лавин. И по положению пиков нетрудно определить, сколько убегающих электронов в среднем приходится ровно на одну лавину.
Потом ищете энергию, при которой среднее число лавин равно 1.
В результате получите энергию seed, которая рождает ровно одну лавину. Получите, сколько частиц приходится ровно на одну лавину (это кстати можно оценить через расчёт длины нарастания лавины ещё, мб так проще будет. Про это в комментарии напишу). И, главное, получите зависимость числа лавин от энергии seed.
Теперь про способ через длину нарастания лавины. Тут проще, чем через распределения,
Берёте ту же ячейку, строите пространственное распределение электронов. Скорее всего, множитель перед экспонентой будет зависеть от энергии seed, а сама экспонента будет всегда одинаковой, поскольку лавины все одинаковые.
Заодно так можно проверить утверждение об одинаковости лавин.
Зная длину нарастания лавины (показатель экспоненты), вы автоматически знаете, сколько частиц в одной лавине. Далее делите количество убегающих электронов в зависимости от энергии seed на число частиц в одной лавине и получаете зависимость количества лавин от от энергии seed.

### 1.7 **Исследование времени достижения равновесия в лавине**

Сколько длин нарастания лавины нужно, чтобы лавина стала устойчивой?
Какой критерий устойчивости? Скорее всего, равновесный спектр.
Исследовать флуктуации спектра до достижения равновесного.
