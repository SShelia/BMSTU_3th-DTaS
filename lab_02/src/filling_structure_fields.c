#include <Windows.h>
#include "../inc/filling_structure_fields.h"

void filling_structure_fields(struct repertoire_of_theatres *theatres)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    for (int i =0; i < 30; i++)
        theatres[i].index = i;


    //Детские театры
    for (int i = 0; i < 1; i++)
        strcpy(theatres[i].theatre_name, "Центральный театр кукол им. С.В. Образцова");

    strcpy(theatres[0].perfomance, "Сказка о рыбаке и рыбке");
    strcpy(theatres[0].producer, "Виктор Воеводин");
    theatres[0].min_ticket_price = 1000;
    theatres[0].max_ticket_price = 2700;
    theatres[0].type = childlike;
    theatres[0].choice.childlike.age = 6;
    theatres[0].choice.childlike.type = fairy_tale;

    /*
    strcpy(theatres[1].perfomance, "Барон Мюнхаузен");
    strcpy(theatres[1].producer, "Оксана Чабанюк");
    theatres[1].min_ticket_price = 700;
    theatres[1].max_ticket_price = 3500;
    theatres[1].type = childlike;
    theatres[1].choice.childlike.age = 6;
    theatres[1].choice.childlike.type = fairy_tale;


    strcpy(theatres[2].perfomance, "Кот в сапогах");
    strcpy(theatres[2].producer, "В. Попрыкин");
    theatres[2].min_ticket_price = 600;
    theatres[2].max_ticket_price = 2700;
    theatres[2].type = childlike;
    theatres[2].choice.childlike.age = 6;
    theatres[2].choice.childlike.type = fairy_tale;


    strcpy(theatres[3].perfomance, "Робинзон");
    strcpy(theatres[3].producer, "Екатерина Образцова");
    theatres[3].min_ticket_price = 800;
    theatres[3].max_ticket_price = 2600;
    theatres[3].type = childlike;
    theatres[3].choice.childlike.age = 6;
    theatres[3].choice.childlike.type = child_play;


    strcpy(theatres[4].perfomance, "Буратино");
    strcpy(theatres[4].producer, "Л. Хаит");
    theatres[4].min_ticket_price = 1000;
    theatres[4].max_ticket_price = 3000;
    theatres[4].type = childlike;
    theatres[4].choice.childlike.age = 6;
    theatres[4].choice.childlike.type = child_play;


    for (int i = 5; i < 10; i++)
        strcpy(theatres[i].theatre_name, "Московский областной государственный театр кукол");

    strcpy(theatres[5].perfomance, "Ревизор");
    strcpy(theatres[5].producer, "Карен Нерсисян");
    theatres[5].min_ticket_price = 500;
    theatres[5].max_ticket_price = 1500;
    theatres[5].type = childlike;
    theatres[5].choice.childlike.age = 8;
    theatres[5].choice.childlike.type = child_play;

    strcpy(theatres[6].perfomance, "Давайте знакомиться");
    strcpy(theatres[6].producer, "Александр Третьяк");
    theatres[6].min_ticket_price = 300;
    theatres[6].max_ticket_price = 1700;
    theatres[6].type = childlike;
    theatres[6].choice.childlike.age = 5;
    theatres[6].choice.childlike.type = child_play;

    strcpy(theatres[7].perfomance, "Про крыши, варенье и привидение");
    strcpy(theatres[7].producer, "Виктор Никоненко");
    theatres[7].min_ticket_price = 500;
    theatres[7].max_ticket_price = 1800;
    theatres[7].type = childlike;
    theatres[7].choice.childlike.age = 5;
    theatres[7].choice.childlike.type = child_play;

    strcpy(theatres[8].perfomance, "Сестрица Алёнушка и братец Иванушка");
    strcpy(theatres[8].producer, "Станислав Железкин");
    theatres[8].min_ticket_price = 440;
    theatres[8].max_ticket_price = 1200;
    theatres[8].type = childlike;
    theatres[8].choice.childlike.age = 8;
    theatres[8].choice.childlike.type = fairy_tale;

    strcpy(theatres[9].perfomance, "Сказка о золотом петушке");
    strcpy(theatres[9].producer, "Денис Казачук");
    theatres[9].min_ticket_price = 500;
    theatres[9].max_ticket_price = 1100;
    theatres[9].type = childlike;
    theatres[9].choice.childlike.age = 6;
    theatres[9].choice.childlike.type = fairy_tale;


    //Для взрослых
    for (int i = 10; i < 20; i++)
        strcpy(theatres[i].theatre_name, "МХТ им.Чехова");

    strcpy(theatres[10].perfomance, "Идеальный муж");
    strcpy(theatres[10].producer, "Константин Богомолов");
    theatres[10].min_ticket_price = 1000;
    theatres[10].max_ticket_price = 3000;
    theatres[10].type = adult;
    theatres[10].choice.adult.type = comedy;

    strcpy(theatres[11].perfomance, "Контрабас");
    strcpy(theatres[11].producer, "Глеб Черепанов");
    theatres[11].min_ticket_price = 1500;
    theatres[11].max_ticket_price = 4500;
    theatres[11].type = adult;
    theatres[11].choice.adult.type = adult_play;

    strcpy(theatres[12].perfomance, "Северный ветер");
    strcpy(theatres[12].producer, "Рената Литвинова");
    theatres[12].min_ticket_price = 2000;
    theatres[12].max_ticket_price = 4500;
    theatres[12].type = adult;
    theatres[12].choice.adult.type = drama;

    strcpy(theatres[13].perfomance, "№13D");
    strcpy(theatres[13].producer, "Владимир Машков");
    theatres[13].min_ticket_price = 1800;
    theatres[13].max_ticket_price = 6000;
    theatres[13].type = adult;
    theatres[13].choice.adult.type = comedy;

    strcpy(theatres[14].perfomance, "Дорогое сокровище");
    strcpy(theatres[14].producer, "Дмитрий Дьяченко");
    theatres[14].min_ticket_price = 1200;
    theatres[14].max_ticket_price = 3000;
    theatres[14].type = adult;
    theatres[14].choice.adult.type = drama;

    strcpy(theatres[15].perfomance, "Человек из рыбы");
    strcpy(theatres[15].producer, "Юрий Бутусов");
    theatres[15].min_ticket_price = 1500;
    theatres[15].max_ticket_price = 3000;
    theatres[15].type = adult;
    theatres[15].choice.adult.type = drama;

    strcpy(theatres[16].perfomance, "Шинель");
    strcpy(theatres[16].producer, "Антон Коваленко");
    theatres[16].min_ticket_price = 1700;
    theatres[16].max_ticket_price = 2900;
    theatres[16].type = adult;
    theatres[16].choice.adult.type = drama;

    strcpy(theatres[17].perfomance, "Спящий принц");
    strcpy(theatres[17].producer, "Роман Самгин");
    theatres[17].min_ticket_price = 1000;
    theatres[17].max_ticket_price = 5000;
    theatres[17].type = adult;
    theatres[17].choice.adult.type = adult_play;

    strcpy(theatres[18].perfomance, "Лес");
    strcpy(theatres[18].producer, "Кирилл Серебренников");
    theatres[18].min_ticket_price = 700;
    theatres[18].max_ticket_price = 2300;
    theatres[18].type = adult;
    theatres[18].choice.adult.type = comedy;


    strcpy(theatres[18].perfomance, "Лес");
    strcpy(theatres[18].producer, "Кирилл Серебренников");
    theatres[18].min_ticket_price = 700;
    theatres[18].max_ticket_price = 2300;
    theatres[18].type = adult;
    theatres[18].choice.adult.type = comedy;

    strcpy(theatres[19].perfomance, "Механика любви");
    strcpy(theatres[19].producer, "Юрий Кравец");
    theatres[19].min_ticket_price = 900;
    theatres[19].max_ticket_price = 2100;
    theatres[19].type = adult;
    theatres[19].choice.adult.type = drama;


    for (int i = 20; i < 25; i++)
        strcpy(theatres[i].theatre_name, "Мастерская Петра Фоменко. Старая сцена");

    strcpy(theatres[20].perfomance, "Сон в летнюю ночь");
    strcpy(theatres[20].producer, "Иван Поповски");
    theatres[20].min_ticket_price = 1000;
    theatres[20].max_ticket_price = 1500;
    theatres[20].type = adult;
    theatres[20].choice.adult.type = comedy;

    strcpy(theatres[21].perfomance, "Волки и овцы");
    strcpy(theatres[21].producer, "Петр Фоменко");
    theatres[21].min_ticket_price = 1100;
    theatres[21].max_ticket_price = 2200;
    theatres[21].type = adult;
    theatres[21].choice.adult.type = drama;

    strcpy(theatres[22].perfomance, "Смешной человек");
    strcpy(theatres[22].producer, "Федор Малышев");
    theatres[22].min_ticket_price = 1300;
    theatres[22].max_ticket_price = 200;
    theatres[22].type = adult;
    theatres[2].choice.adult.type = adult_play;

    strcpy(theatres[23].perfomance, "Мастер и Маргарита");
    strcpy(theatres[23].producer, "Полина Агуреева");
    theatres[23].min_ticket_price = 900;
    theatres[23].max_ticket_price = 2100;
    theatres[23].type = adult;
    theatres[23].choice.adult.type = drama;

    strcpy(theatres[24].perfomance, "Души");
    strcpy(theatres[24].producer, "Федор Малышев");
    theatres[24].min_ticket_price = 1000;
    theatres[24].max_ticket_price = 1500;
    theatres[24].type = adult;
    theatres[24].choice.adult.type = drama;


    //Музыкальные спектакли
    for (int i = 25; i < 30; i++)
        strcpy(theatres[i].theatre_name, "Театр «Московская оперетта»");

    strcpy(theatres[25].perfomance, "Анна Каренина");
    strcpy(theatres[25].producer, "Алина Чевик");
    theatres[25].min_ticket_price = 3000;
    theatres[25].max_ticket_price = 5000;
    theatres[25].type = musical;
    strcpy(theatres[25].choice.musical.composer, "Роман Игнатьев");
    strcpy(theatres[25].choice.musical.country, "Россия");
    theatres[25].choice.musical.min_age = 6;
    theatres[25].choice.musical.duration = 120;

    strcpy(theatres[26].perfomance, "Ромео и Джульета");
    strcpy(theatres[26].producer, "Алексей Франдетти");
    theatres[26].min_ticket_price = 1800;
    theatres[26].max_ticket_price = 4200;
    theatres[26].type = musical;
    strcpy(theatres[26].choice.musical.composer, "Константин Хватынец");
    strcpy(theatres[26].choice.musical.country, "Россия");
    theatres[26].choice.musical.min_age = 12;
    theatres[26].choice.musical.duration = 120;


    strcpy(theatres[27].perfomance, "Весёлая вдова");
    strcpy(theatres[27].producer, "Игорь Барабашёв");
    theatres[27].min_ticket_price = 2200;
    theatres[27].max_ticket_price = 4300;
    theatres[27].type = musical;
    strcpy(theatres[27].choice.musical.composer, "Константин Хватынец");
    strcpy(theatres[27].choice.musical.country, "Россия");
    theatres[27].choice.musical.min_age = 6;
    theatres[27].choice.musical.duration = 100;


    strcpy(theatres[28].perfomance, "Джейн Эйр");
    strcpy(theatres[28].producer, "Алина Чевик");
    theatres[28].min_ticket_price = 2800;
    theatres[28].max_ticket_price = 5000;
    theatres[28].type = musical;
    strcpy(theatres[28].choice.musical.composer, "Константин Хватынец");
    strcpy(theatres[28].choice.musical.country, "Россия");
    theatres[28].choice.musical.min_age = 6;
    theatres[28].choice.musical.duration = 130;

    strcpy(theatres[29].perfomance, "Золушка");
    strcpy(theatres[29].producer, "Ж.Жердер");
    theatres[29].min_ticket_price = 1200;
    theatres[29].max_ticket_price = 3400;
    theatres[29].type = musical;
    strcpy(theatres[29].choice.musical.composer, "А.Семёнов");
    strcpy(theatres[29].choice.musical.country, "Россия");
    theatres[29].choice.musical.min_age = 0;
    theatres[29].choice.musical.duration = 90;


    for (int i = 30; i < 35; i++)
        strcpy(theatres[i].theatre_name, "Московский театр мюзикла");

    strcpy(theatres[30].perfomance, "Преступление и наказание");
    strcpy(theatres[30].producer, "Андрей Кончаловский");
    theatres[30].min_ticket_price = 1000;
    theatres[30].max_ticket_price = 3000;
    theatres[30].type = musical;
    strcpy(theatres[30].choice.musical.composer, "Эдуард Артемьев");
    strcpy(theatres[30].choice.musical.country, "Россия");
    theatres[30].choice.musical.min_age = 12;
    theatres[30].choice.musical.duration = 160;


    strcpy(theatres[31].perfomance, "Праймтайм");
    strcpy(theatres[31].producer, "Марина Швыдкая");
    theatres[31].min_ticket_price = 1100;
    theatres[31].max_ticket_price = 2300;
    theatres[31].type = musical;
    strcpy(theatres[31].choice.musical.composer, "Максим Лепаж");
    strcpy(theatres[31].choice.musical.country, "Канада");
    theatres[31].choice.musical.min_age = 12;
    theatres[31].choice.musical.duration = 170;

    strcpy(theatres[32].perfomance, "Чудеса и куралесы");
    strcpy(theatres[32].producer, "Марина Швыдкая");
    theatres[32].min_ticket_price = 1600;
    theatres[32].max_ticket_price = 3100;
    theatres[32].type = musical;
    strcpy(theatres[32].choice.musical.composer, "Владимир Баскин");
    strcpy(theatres[32].choice.musical.country, "Россия");
    theatres[32].choice.musical.min_age = 6;
    theatres[32].choice.musical.duration = 120;


    strcpy(theatres[33].perfomance, "Реверс");
    strcpy(theatres[33].producer, "Ирина Дрожжина");
    theatres[33].min_ticket_price = 1300;
    theatres[33].max_ticket_price = 3700;
    theatres[33].type = musical;
    strcpy(theatres[33].choice.musical.composer, "Миша Мищенко");
    strcpy(theatres[33].choice.musical.country, "Россия");
    theatres[33].choice.musical.min_age = 18;
    theatres[33].choice.musical.duration = 95;


    strcpy(theatres[34].perfomance, "Принцесса цирка");
    strcpy(theatres[34].producer, "Себастьян Солдевилья");
    theatres[34].min_ticket_price = 900;
    theatres[34].max_ticket_price = 2500;
    theatres[34].type = musical;
    strcpy(theatres[34].choice.musical.composer, "Имре Кальман");
    strcpy(theatres[34].choice.musical.country, "Канада");
    theatres[34].choice.musical.min_age = 6;
    theatres[34].choice.musical.duration = 180;

    for (int i = 35; i < 40; i++)
        strcpy(theatres[i].theatre_name, "Государственный музыкальный театр «На Басманной»");

    strcpy(theatres[35].perfomance, "Волшебный цветок");
    strcpy(theatres[35].producer, "Вячеслав Архипов");
    theatres[35].min_ticket_price = 800;
    theatres[35].max_ticket_price = 1300;
    theatres[35].type = musical;
    strcpy(theatres[35].choice.musical.composer, "Евгения Грецкая");
    strcpy(theatres[35].choice.musical.country, "Россия");
    theatres[35].choice.musical.min_age = 4;
    theatres[35].choice.musical.duration = 180;


    strcpy(theatres[36].perfomance, "Огниво");
    strcpy(theatres[36].producer, "Наталья Тимофеева");
    theatres[36].min_ticket_price = 600;
    theatres[36].max_ticket_price = 1200;
    theatres[36].type = musical;
    strcpy(theatres[36].choice.musical.composer, "Ольга Петрова");
    strcpy(theatres[36].choice.musical.country, "Россия");
    theatres[36].choice.musical.min_age = 6;
    theatres[36].choice.musical.duration = 120;

    strcpy(theatres[37].perfomance, "Волшебная лампа Аладдина");
    strcpy(theatres[37].producer, "Жанна Тертерян");
    theatres[37].min_ticket_price = 800;
    theatres[37].max_ticket_price = 1300;
    theatres[37].type = musical;
    strcpy(theatres[37].choice.musical.composer, "Юрий Алябов");
    strcpy(theatres[37].choice.musical.country, "Россия");
    theatres[37].choice.musical.min_age = 4;
    theatres[37].choice.musical.duration = 90;


    strcpy(theatres[38].perfomance, "Спящая красавица");
    strcpy(theatres[38].producer, "Вячеслав Архипов");
    theatres[38].min_ticket_price = 1000;
    theatres[38].max_ticket_price = 1500;
    theatres[38].type = musical;
    strcpy(theatres[38].choice.musical.composer, "Валерий Петров");
    strcpy(theatres[38].choice.musical.country, "Россия");
    theatres[38].choice.musical.min_age = 6;
    theatres[38].choice.musical.duration = 110;


    strcpy(theatres[39].perfomance, "Сказка о царе Салтане");
    strcpy(theatres[39].producer, "Елена Лепнева");
    theatres[39].min_ticket_price = 800;
    theatres[39].max_ticket_price = 2200;
    theatres[39].type = musical;
    strcpy(theatres[39].choice.musical.composer, "Валерий Петров");
    strcpy(theatres[39].choice.musical.country, "Россия");
    theatres[39].choice.musical.min_age = 0;
    theatres[39].choice.musical.duration = 110;



    for (int i = 40; i < 80; i++)
        theatres[i].index = i;


    //Детские театры
    for (int i = 40; i < 45; i++)
        strcpy(theatres[i].theatre_name, "Центральный театр кукол им. С.В. Образцова");

    strcpy(theatres[40].perfomance, "Буратино");
    strcpy(theatres[40].producer, "Л. Хаит");
    theatres[40].min_ticket_price = 1000;
    theatres[40].max_ticket_price = 3000;
    theatres[40].type = childlike;
    theatres[40].choice.childlike.age = 6;
    theatres[40].choice.childlike.type = child_play;

    strcpy(theatres[41].perfomance, "Барон Мюнхаузен");
    strcpy(theatres[41].producer, "Оксана Чабанюк");
    theatres[41].min_ticket_price = 700;
    theatres[41].max_ticket_price = 3500;
    theatres[41].type = childlike;
    theatres[41].choice.childlike.age = 6;
    theatres[41].choice.childlike.type = fairy_tale;

    strcpy(theatres[42].perfomance, "Сказка о рыбаке и рыбке");
    strcpy(theatres[42].producer, "Виктор Воеводин");
    theatres[42].min_ticket_price = 1000;
    theatres[42].max_ticket_price = 2700;
    theatres[42].type = childlike;
    theatres[42].choice.childlike.age = 6;
    theatres[42].choice.childlike.type = fairy_tale;

    strcpy(theatres[43].perfomance, "Робинзон");
    strcpy(theatres[43].producer, "Екатерина Образцова");
    theatres[43].min_ticket_price = 800;
    theatres[43].max_ticket_price = 2600;
    theatres[43].type = childlike;
    theatres[43].choice.childlike.age = 6;
    theatres[43].choice.childlike.type = child_play;

    strcpy(theatres[44].perfomance, "Кот в сапогах");
    strcpy(theatres[44].producer, "В. Попрыкин");
    theatres[44].min_ticket_price = 600;
    theatres[44].max_ticket_price = 2700;
    theatres[44].type = childlike;
    theatres[44].choice.childlike.age = 6;
    theatres[44].choice.childlike.type = fairy_tale;



    for (int i = 45; i < 70; i++)
        strcpy(theatres[i].theatre_name, "Московский областной государственный театр кукол");


    strcpy(theatres[45].perfomance, "Про крыши, варенье и привидение");
    strcpy(theatres[45].producer, "Виктор Никоненко");
    theatres[45].min_ticket_price = 500;
    theatres[45].max_ticket_price = 1800;
    theatres[45].type = childlike;
    theatres[45].choice.childlike.age = 5;
    theatres[45].choice.childlike.type = child_play;

    strcpy(theatres[46].perfomance, "Давайте знакомиться");
    strcpy(theatres[46].producer, "Александр Третьяк");
    theatres[46].min_ticket_price = 300;
    theatres[46].max_ticket_price = 1700;
    theatres[46].type = childlike;
    theatres[46].choice.childlike.age = 5;
    theatres[46].choice.childlike.type = child_play;

    strcpy(theatres[47].perfomance, "Сказка о золотом петушке");
    strcpy(theatres[47].producer, "Денис Казачук");
    theatres[47].min_ticket_price = 500;
    theatres[47].max_ticket_price = 1100;
    theatres[47].type = childlike;
    theatres[47].choice.childlike.age = 6;
    theatres[47].choice.childlike.type = fairy_tale;

    strcpy(theatres[48].perfomance, "Ревизор");
    strcpy(theatres[48].producer, "Карен Нерсисян");
    theatres[48].min_ticket_price = 500;
    theatres[48].max_ticket_price = 1500;
    theatres[48].type = childlike;
    theatres[48].choice.childlike.age = 8;
    theatres[48].choice.childlike.type = child_play;


    strcpy(theatres[49].perfomance, "Сестрица Алёнушка и братец Иванушка");
    strcpy(theatres[49].producer, "Станислав Железкин");
    theatres[49].min_ticket_price = 440;
    theatres[49].max_ticket_price = 1200;
    theatres[49].type = childlike;
    theatres[49].choice.childlike.age = 8;
    theatres[49].choice.childlike.type = fairy_tale;



    //Для взрослых
    for (int i = 50; i < 60; i++)
        strcpy(theatres[i].theatre_name, "МХТ им.Чехова");


    strcpy(theatres[50].perfomance, "Механика любви");
    strcpy(theatres[50].producer, "Юрий Кравец");
    theatres[50].min_ticket_price = 900;
    theatres[50].max_ticket_price = 2100;
    theatres[50].type = adult;
    theatres[50].choice.adult.type = drama;

    strcpy(theatres[51].perfomance, "№13D");
    strcpy(theatres[51].producer, "Владимир Машков");
    theatres[51].min_ticket_price = 1800;
    theatres[51].max_ticket_price = 6000;
    theatres[51].type = adult;
    theatres[51].choice.adult.type = comedy;

    strcpy(theatres[52].perfomance, "Идеальный муж");
    strcpy(theatres[52].producer, "Константин Богомолов");
    theatres[52].min_ticket_price = 1000;
    theatres[52].max_ticket_price = 3000;
    theatres[52].type = adult;
    theatres[52].choice.adult.type = comedy;


    strcpy(theatres[53].perfomance, "Северный ветер");
    strcpy(theatres[53].producer, "Рената Литвинова");
    theatres[53].min_ticket_price = 2000;
    theatres[53].max_ticket_price = 4500;
    theatres[53].type = adult;
    theatres[53].choice.adult.type = drama;

    strcpy(theatres[54].perfomance, "Контрабас");
    strcpy(theatres[54].producer, "Глеб Черепанов");
    theatres[54].min_ticket_price = 1500;
    theatres[54].max_ticket_price = 4500;
    theatres[54].type = adult;
    theatres[54].choice.adult.type = adult_play;


    strcpy(theatres[55].perfomance, "Человек из рыбы");
    strcpy(theatres[55].producer, "Юрий Бутусов");
    theatres[55].min_ticket_price = 1500;
    theatres[55].max_ticket_price = 3000;
    theatres[55].type = adult;
    theatres[55].choice.adult.type = drama;

    strcpy(theatres[56].perfomance, "Шинель");
    strcpy(theatres[56].producer, "Антон Коваленко");
    theatres[56].min_ticket_price = 1700;
    theatres[56].max_ticket_price = 2900;
    theatres[56].type = adult;
    theatres[56].choice.adult.type = drama;

    strcpy(theatres[57].perfomance, "Дорогое сокровище");
    strcpy(theatres[57].producer, "Дмитрий Дьяченко");
    theatres[57].min_ticket_price = 1200;
    theatres[57].max_ticket_price = 3000;
    theatres[57].type = adult;
    theatres[57].choice.adult.type = drama;

    strcpy(theatres[58].perfomance, "Спящий принц");
    strcpy(theatres[58].producer, "Роман Самгин");
    theatres[58].min_ticket_price = 1000;
    theatres[58].max_ticket_price = 5000;
    theatres[58].type = adult;
    theatres[58].choice.adult.type = adult_play;


    strcpy(theatres[59].perfomance, "Лес");
    strcpy(theatres[59].producer, "Кирилл Серебренников");
    theatres[59].min_ticket_price = 700;
    theatres[59].max_ticket_price = 2300;
    theatres[59].type = adult;
    theatres[59].choice.adult.type = comedy;



    for (int i = 60; i < 65; i++)
        strcpy(theatres[i].theatre_name, "Мастерская Петра Фоменко. Старая сцена");

    strcpy(theatres[60].perfomance, "Сон в летнюю ночь");
    strcpy(theatres[60].producer, "Иван Поповски");
    theatres[60].min_ticket_price = 1000;
    theatres[60].max_ticket_price = 1500;
    theatres[60].type = adult;
    theatres[60].choice.adult.type = comedy;

    strcpy(theatres[61].perfomance, "Мастер и Маргарита");
    strcpy(theatres[61].producer, "Полина Агуреева");
    theatres[61].min_ticket_price = 900;
    theatres[61].max_ticket_price = 2100;
    theatres[61].type = adult;
    theatres[61].choice.adult.type = drama;

    strcpy(theatres[62].perfomance, "Смешной человек");
    strcpy(theatres[62].producer, "Федор Малышев");
    theatres[62].min_ticket_price = 1300;
    theatres[62].max_ticket_price = 200;
    theatres[62].type = adult;
    theatres[62].choice.adult.type = adult_play;

    strcpy(theatres[63].perfomance, "Души");
    strcpy(theatres[63].producer, "Федор Малышев");
    theatres[63].min_ticket_price = 1000;
    theatres[63].max_ticket_price = 1500;
    theatres[63].type = adult;
    theatres[63].choice.adult.type = drama;


    strcpy(theatres[64].perfomance, "Волки и овцы");
    strcpy(theatres[64].producer, "Петр Фоменко");
    theatres[64].min_ticket_price = 1100;
    theatres[64].max_ticket_price = 2200;
    theatres[64].type = adult;
    theatres[64].choice.adult.type = drama;


    //Музыкальные спектакли
    for (int i = 65; i < 70; i++)
        strcpy(theatres[i].theatre_name, "Театр «Московская оперетта»");

    strcpy(theatres[65].perfomance, "Джейн Эйр");
    strcpy(theatres[65].producer, "Алина Чевик");
    theatres[65].min_ticket_price = 2800;
    theatres[65].max_ticket_price = 5000;
    theatres[65].type = musical;
    strcpy(theatres[65].choice.musical.composer, "Константин Хватынец");
    strcpy(theatres[65].choice.musical.country, "Россия");
    theatres[65].choice.musical.min_age = 6;
    theatres[65].choice.musical.duration = 130;

    strcpy(theatres[66].perfomance, "Анна Каренина");
    strcpy(theatres[66].producer, "Алина Чевик");
    theatres[66].min_ticket_price = 3000;
    theatres[66].max_ticket_price = 5000;
    theatres[66].type = musical;
    strcpy(theatres[66].choice.musical.composer, "Роман Игнатьев");
    strcpy(theatres[66].choice.musical.country, "Россия");
    theatres[66].choice.musical.min_age = 6;
    theatres[66].choice.musical.duration = 120;


    strcpy(theatres[67].perfomance, "Золушка");
    strcpy(theatres[67].producer, "Ж.Жердер");
    theatres[67].min_ticket_price = 1200;
    theatres[67].max_ticket_price = 3400;
    theatres[67].type = musical;
    strcpy(theatres[67].choice.musical.composer, "А.Семёнов");
    strcpy(theatres[67].choice.musical.country, "Россия");
    theatres[67].choice.musical.min_age = 0;
    theatres[67].choice.musical.duration = 90;

    strcpy(theatres[68].perfomance, "Весёлая вдова");
    strcpy(theatres[68].producer, "Игорь Барабашёв");
    theatres[68].min_ticket_price = 2200;
    theatres[68].max_ticket_price = 4300;
    theatres[68].type = musical;
    strcpy(theatres[68].choice.musical.composer, "Константин Хватынец");
    strcpy(theatres[68].choice.musical.country, "Россия");
    theatres[68].choice.musical.min_age = 6;
    theatres[68].choice.musical.duration = 100;


    strcpy(theatres[69].perfomance, "Ромео и Джульета");
    strcpy(theatres[69].producer, "Алексей Франдетти");
    theatres[69].min_ticket_price = 1800;
    theatres[69].max_ticket_price = 4200;
    theatres[69].type = musical;
    strcpy(theatres[69].choice.musical.composer, "Константин Хватынец");
    strcpy(theatres[69].choice.musical.country, "Россия");
    theatres[69].choice.musical.min_age = 12;
    theatres[69].choice.musical.duration = 120;


    for (int i = 70; i < 75; i++)
        strcpy(theatres[i].theatre_name, "Московский театр мюзикла");

    strcpy(theatres[70].perfomance, "Преступление и наказание");
    strcpy(theatres[70].producer, "Андрей Кончаловский");
    theatres[70].min_ticket_price = 1000;
    theatres[70].max_ticket_price = 3000;
    theatres[70].type = musical;
    strcpy(theatres[70].choice.musical.composer, "Эдуард Артемьев");
    strcpy(theatres[70].choice.musical.country, "Россия");
    theatres[70].choice.musical.min_age = 12;
    theatres[70].choice.musical.duration = 160;


    strcpy(theatres[71].perfomance, "Праймтайм");
    strcpy(theatres[71].producer, "Марина Швыдкая");
    theatres[71].min_ticket_price = 1100;
    theatres[71].max_ticket_price = 2300;
    theatres[71].type = musical;
    strcpy(theatres[71].choice.musical.composer, "Максим Лепаж");
    strcpy(theatres[71].choice.musical.country, "Канада");
    theatres[71].choice.musical.min_age = 12;
    theatres[71].choice.musical.duration = 170;

    strcpy(theatres[72].perfomance, "Чудеса и куралесы");
    strcpy(theatres[72].producer, "Марина Швыдкая");
    theatres[72].min_ticket_price = 1600;
    theatres[72].max_ticket_price = 3100;
    theatres[72].type = musical;
    strcpy(theatres[72].choice.musical.composer, "Владимир Баскин");
    strcpy(theatres[72].choice.musical.country, "Россия");
    theatres[72].choice.musical.min_age = 6;
    theatres[72].choice.musical.duration = 120;


    strcpy(theatres[73].perfomance, "Реверс");
    strcpy(theatres[73].producer, "Ирина Дрожжина");
    theatres[73].min_ticket_price = 1300;
    theatres[73].max_ticket_price = 3700;
    theatres[73].type = musical;
    strcpy(theatres[73].choice.musical.composer, "Миша Мищенко");
    strcpy(theatres[73].choice.musical.country, "Россия");
    theatres[73].choice.musical.min_age = 18;
    theatres[73].choice.musical.duration = 95;


    strcpy(theatres[74].perfomance, "Принцесса цирка");
    strcpy(theatres[74].producer, "Себастьян Солдевилья");
    theatres[74].min_ticket_price = 900;
    theatres[74].max_ticket_price = 2500;
    theatres[74].type = musical;
    strcpy(theatres[74].choice.musical.composer, "Имре Кальман");
    strcpy(theatres[74].choice.musical.country, "Канада");
    theatres[74].choice.musical.min_age = 6;
    theatres[74].choice.musical.duration = 180;

    for (int i = 75; i < 80; i++)
        strcpy(theatres[i].theatre_name, "Государственный музыкальный театр «На Басманной»");


    strcpy(theatres[75].perfomance, "Сказка о царе Салтане");
    strcpy(theatres[75].producer, "Елена Лепнева");
    theatres[75].min_ticket_price = 800;
    theatres[75].max_ticket_price = 2200;
    theatres[75].type = musical;
    strcpy(theatres[75].choice.musical.composer, "Валерий Петров");
    strcpy(theatres[75].choice.musical.country, "Россия");
    theatres[75].choice.musical.min_age = 0;
    theatres[75].choice.musical.duration = 110;

    strcpy(theatres[76].perfomance, "Волшебная лампа Аладдина");
    strcpy(theatres[76].producer, "Жанна Тертерян");
    theatres[76].min_ticket_price = 800;
    theatres[76].max_ticket_price = 1300;
    theatres[76].type = musical;
    strcpy(theatres[76].choice.musical.composer, "Юрий Алябов");
    strcpy(theatres[76].choice.musical.country, "Россия");
    theatres[76].choice.musical.min_age = 4;
    theatres[76].choice.musical.duration = 90;

    strcpy(theatres[77].perfomance, "Спящая красавица");
    strcpy(theatres[77].producer, "Вячеслав Архипов");
    theatres[77].min_ticket_price = 1000;
    theatres[77].max_ticket_price = 1500;
    theatres[77].type = musical;
    strcpy(theatres[77].choice.musical.composer, "Валерий Петров");
    strcpy(theatres[77].choice.musical.country, "Россия");
    theatres[77].choice.musical.min_age = 6;
    theatres[77].choice.musical.duration = 110;

    strcpy(theatres[78].perfomance, "Волшебный цветок");
    strcpy(theatres[78].producer, "Вячеслав Архипов");
    theatres[78].min_ticket_price = 800;
    theatres[78].max_ticket_price = 1300;
    theatres[78].type = musical;
    strcpy(theatres[78].choice.musical.composer, "Евгения Грецкая");
    strcpy(theatres[78].choice.musical.country, "Россия");
    theatres[78].choice.musical.min_age = 4;
    theatres[78].choice.musical.duration = 180;


    strcpy(theatres[79].perfomance, "Огниво");
    strcpy(theatres[79].producer, "Наталья Тимофеева");
    theatres[79].min_ticket_price = 600;
    theatres[79].max_ticket_price = 1200;
    theatres[79].type = musical;
    strcpy(theatres[79].choice.musical.composer, "Ольга Петрова");
    strcpy(theatres[79].choice.musical.country, "Россия");
    theatres[79].choice.musical.min_age = 6;
    theatres[79].choice.musical.duration = 120;

    */

}
