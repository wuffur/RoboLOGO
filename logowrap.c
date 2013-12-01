struct iorobo(
file usbsig; //поток входной - записи
file usbcontr; //поток выходной - команды управления
char usbdesc; //дескиптор сигнала USB - версия и прочии данные
int usbstat; //статус USB включён или выключен
)

#ifdef simplerobot
{
#define вперёд goto_forward(&iorobo)
#define назад goto_backward(&iorobo)
#define влево turn_left(&iorobo)
#define вправо turn_right(&iorobo)

}
#elif hexopod 
{
#define вперёд goto_forward(&iorobo)
#define назад goto_backward(&iorobo)
#define вбоквлево strafe_left(&iorobo)
#define вбоквправо strafe_left(&iorobo)
#define вбоклв strafe_left(&iorobo)
#define вбокпр strafe_left(&iorobo)
#define влево turn_left(&iorobo)
#define вправо turn_right(&iorobo)
}

#endif

#define справка printf("
Добро пожаловать в РобоЛОГО!\n
Ученик! Мы приветстуем тебя и твой начинающийся удивительный и захватывающий путь в мир роботов!\n
1)Для начала осмотрись на приборы которые есть в комплекте - попроси родителей, своего учителя или консультанта в магазине правильно собрать их.\n
Если справился с первым заданием то держи второе:\n
2)Если ты собрал то пожалуйста, следуя инструкции собери своё первое игровое поле - оно выглядит как поле из клеток в виде прямоугольника. 
Оно должно быть уже собрано. Если всё собрано правильно и прибор собран верно, то на карте будет большое зелёное поле. Получилось? Тогда переходи к третьему шагу
3)Ты берёшь два типа материала - конструктора карты для поля - матерчатая ткань(она невидима для сонара) и светоотражающая 
зеркальная поверхность(фольга невидима для сенсора!). По умолчанию программа принимает фольгу за водную гладь мира, а ткань за рельефную гору.
Осмотрись подробно и аккуратно расставь кусочки для создания рельефа местности, ты можешь переходить по двум режимам - с/без рендеринга поверхность. 
Рендеринг - это компьютерная обработка поверхности, чтобы они выглядили реалистично. \n
4)Доставай своего робота и проверь в режиме \"обучения\", может ли твой робот управляться дистанционно с помощью компьютера. 
Если да, то можешь начинать игру, только не забудь позвать друзей, вместе веселее! 
В режиме \"из А в Б\" роботу будут даваться специальные \'перки\', и выполняя их сможет дойти до конечной точки
В режиме \" Квест \" робот будет выполнять различные интересные задачи, благодаря которым ты попадёшь в увлекательную историю.
Ты так же можешь сохранить свою игру где закончил или даже отправить свою карту друзьям, но не сейв(для этого нужно просто переписать файл БД, 
но все достижения твоего друга испортятся).\n
В добрый путь юный исследователь и пусть твой робот найдёт своё место в РобоЛОГОве(Hall of fame - RoboHALL-o-go)!\n"
