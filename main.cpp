#include <iostream>
#include <string>
#include <vector>

class Quest {
public:
    std::string title;
    std::string description;
    bool isCompleted;
    int requiredAmount; // Количество, необходимое для завершения квеста
    int collectedAmount; // Количество, собранное игроком

    Quest(std::string t, std::string d, int reqAmount = 0) 
        : title(t), description(d), isCompleted(false), requiredAmount(reqAmount), collectedAmount(0) {}

    void collect() {
        if (!isCompleted && collectedAmount < requiredAmount) {
            collectedAmount++;
            std::cout << "Вы собрали бутылку Silex-Cola! Всего: " << collectedAmount << "/" << requiredAmount << std::endl;
            if (collectedAmount >= requiredAmount) {
                completeQuest();
            }
        }
    }

    void completeQuest() {
        isCompleted = true;
        std::cout << "Quest completed: " << title << std::endl;
    }
};

class Player {
public:
    std::string name;
    std::vector<Quest> quests;

    Player(std::string n) : name(n) {}

    void addQuest(Quest quest) {
        quests.push_back(quest);
    }

    void showQuests() {
        for (const auto& quest : quests) {
            std::cout << "Quest: " << quest.title << " - " << (quest.isCompleted ? "Completed" : "Not Completed") << std::endl;
        }
    }
};

// Прототип функции для взаимодействия с терминалом работника
void interactWithTerminal();

// Функция для создания и отображения карты 5x5 с обозначением местоположения игрока и локации Silex
void createMap(int playerX, int playerY) {
    const int size = 5;
    char map[size][size];

    // Заполнение карты символами
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            map[i][j] = '.'; // '.' обозначает пустую клетку
        }
    }

    // Установка местоположения игрока
    map[playerY][playerX] = 'Y'; // 'Y' обозначает местоположение игрока

    // Установка локации Silex
    int silexX = 4; // Координаты Silex по оси X
    int silexY = 0; // Координаты Silex по оси Y
    map[silexY][silexX] = 'S'; // 'S' обозначает локацию Silex

    // Установка локации Сухая пещера
    int dryCaveX = 0; // Координаты Сухой пещеры по оси X
    int dryCaveY = 4; // Координаты Сухой пещеры по оси Y
    map[dryCaveY][dryCaveX] = 'D'; // 'D' обозначает локацию Сухая пещера

    // Установка локации Арт-деко
    int artDecoX = 2; // Координаты Арт-деко по оси X
    int artDecoY = 1; // Координаты Арт-деко по оси Y
    map[artDecoY][artDecoX] = 'A'; // 'A' обозначает локацию Арт-деко

    // Отображение карты
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// Функция для взаимодействия с локацией Silex
void interactWithSilex(Player& player) {
    std::cout << "Вы находитесь в Silex. Здесь продается газировка Silex-Cola!" << std::endl;
    std::cout << "Кто-то говорит: 'Эта газировка - лучший способ утолить жажду!'" << std::endl;

    // Добавление квеста, связанного с Silex-Cola
    Quest silexColaQuest("Найти Silex-Cola", "Принести Silex-Cola для местного жителя.", 5);
    player.addQuest(silexColaQuest);
    std::cout << "Вы получили новый квест: " << silexColaQuest.title << std::endl;

    // Взаимодействие с терминалом
    char terminalCommand;
    std::cout << "Хотите прочитать терминал работника? (y/n): ";
    std::cin >> terminalCommand;

    if (terminalCommand == 'y') {
        interactWithTerminal();
    }
}

// Функция для взаимодействия с терминалом работника
void interactWithTerminal() {
    std::cout << "Терминал работника: " << std::endl;
    std::cout << "Внимание! Ядерные бомбы были сброшены на фабрику!" << std::endl;
    std::cout << "Ситуация критическая. Работники должны эвакуироваться немедленно!" << std::endl;
    std::cout << "Мы потеряли связь с центральным офисом. Пожалуйста, оставайтесь в укрытии!" << std::endl;
    std::cout << "Не забывайте о Silex-Cola, она может спасти вам жизнь!" << std::endl;
}

// Добавление новой локации "Сухая пещера" и NPC
void interactWithDryCave(Player& player) {
    std::cout << "Вы находитесь в Сухой пещере. Здесь вы встречаете старого искателя приключений!" << std::endl;
    std::cout << "Он говорит: 'Я потерял свой амулет в этой пещере. Помоги мне его найти!'" << std::endl;

    // Добавление квеста, связанного с амулетом
    Quest amuletQuest("Найти амулет", "Найти амулет, потерянный старым искателем приключений.", 1);
    player.addQuest(amuletQuest);
    std::cout << "Вы получили новый квест: " << amuletQuest.title << std::endl;
}

// Функция для продолжения чтения информации в терминале
void continueReading() {
    std::cout << "Исследования показывают, что летучие мыши мутировали из-за воздействия радиации." << std::endl;
    std::cout << "Некоторые из них стали значительно больше и агрессивнее." << std::endl;
    std::cout << "Рекомендуется избегать встречи с мутантами, так как они могут быть опасны." << std::endl;
}

// Обновление функции interactWithCaveTerminal для добавления новой информации
void interactWithCaveTerminal() {
    std::cout << "Терминал в Сухой пещере: " << std::endl;
    std::cout << "Исследования летучих мышей показывают, что они могут обнаруживать объекты в темноте." << std::endl;
    std::cout << "Некоторые виды летучих мышей могут быть опасны, если их потревожить." << std::endl;
    std::cout << "Рекомендуется быть осторожным при исследовании пещеры." << std::endl;

    char continueCommand;
    std::cout << "Хотите продолжить чтение? (y/n): ";
    std::cin >> continueCommand;

    if (continueCommand == 'y') {
        continueReading(); // Продолжение чтения
    } else {
        std::cout << "Вы решили не продолжать чтение." << std::endl;
    }
}

// Функция для возврата амулета NPC
void returnAmulet(Player& player) {
    if (!player.quests.empty() && player.quests.back().isCompleted) {
        std::cout << "Вы вернули амулет старому искателю приключений!" << std::endl;
        std::cout << "Он благодарит вас и говорит: 'Спасибо! Теперь я могу вернуться к своим исследованиям!'" << std::endl;
        player.quests.pop_back(); // Удаляем квест после его завершения
    } else {
        std::cout << "У вас нет амулета, чтобы вернуть!" << std::endl;
    }
}

// Обновление функции chooseCaveAction для добавления возврата амулета
void chooseCaveAction(Player& player) {
    std::cout << "Вы находитесь в Сухой пещере. Что вы хотите сделать?" << std::endl;
    std::cout << "1. Исследовать пещеру." << std::endl;
    std::cout << "2. Попытаться найти амулет." << std::endl;
    std::cout << "3. Вернуть амулет старому искателю приключений." << std::endl;
    std::cout << "4. Покинуть пещеру." << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Вы начали исследовать пещеру. Внезапно вы слышите шорох!" << std::endl;
            // Здесь можно добавить дополнительные события
            break;
        case 2:
            std::cout << "Вы начали искать амулет. После долгих поисков вы находите его!" << std::endl;
            // Завершение квеста
            player.quests.back().completeQuest();
            break;
        case 3:
            returnAmulet(player); // Возврат амулета
            break;
        case 4:
            std::cout << "Вы решили покинуть пещеру." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
            chooseCaveAction(player); // Повторный вызов для нового выбора
            break;
    }
}

// Обновление функции enterDryCave для добавления выбора действий
void enterDryCave(Player& player) {
    std::cout << "Вы вошли в Сухую пещеру. Здесь темно и сыро." << std::endl;

    char terminalCommand;
    std::cout << "Хотите прочитать терминал в пещере? (y/n): ";
    std::cin >> terminalCommand;

    if (terminalCommand == 'y') {
        interactWithCaveTerminal(); // Взаимодействие с терминалом
    } else {
        std::cout << "Вы решили не читать терминал." << std::endl;
    }

    chooseCaveAction(player); // Вызов функции выбора действий
}

// Функция для взаимодействия с "Зданием Мира"
void interactWithWorldBuilding(Player& player) {
    std::cout << "Вы вошли в Здание Мира. Здесь царит атмосфера гармонии и процветания." << std::endl;
    std::cout << "Внутри вы видите высокие колонны и изысканные фрески, которые рассказывают о великих достижениях человечества." << std::endl;
    
    std::cout << "Вы замечаете старого мудреца, который сидит на скамейке и читает книгу." << std::endl;
    std::cout << "Он поднимает голову и говорит: 'Добро пожаловать! Я могу рассказать вам о великих событиях прошлого.'" << std::endl;

    std::cout << "Что вы хотите сделать?" << std::endl;
    std::cout << "1. Поговорить с мудрецом." << std::endl;
    std::cout << "2. Исследовать здание." << std::endl;
    std::cout << "3. Вернуться на улицу." << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Мудрец начинает рассказывать о великих событиях, которые изменили ход истории." << std::endl;
            std::cout << "Он говорит: 'Фабрики, которые были построены в прошлом, изменили облик нашего общества. Они производили товары в больших объемах, что сделало их доступными для всех.'" << std::endl;
            std::cout << "'Однако, с ростом производства, качество некоторых продуктов стало снижаться. Дешевые товары заполнили рынок, и люди начали забывать о ценности ручной работы и уникальности.'" << std::endl;
            std::cout << "'Это привело к тому, что многие мастера и ремесленники оказались в трудном положении, так как их изделия не могли конкурировать с массовым производством.'" << std::endl;
            std::cout << "Вы чувствуете, как знания наполняют вас вдохновением." << std::endl;
            break;
        case 2:
            std::cout << "Вы исследуете здание и находите старинные артефакты, которые рассказывают о прошлом." << std::endl;
            // Здесь можно добавить дополнительные события или квесты
            break;
        case 3:
            std::cout << "Вы решили вернуться на улицу." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
            interactWithWorldBuilding(player); // Повторный вызов для нового выбора
            break;
    }
}

// Функция для взаимодействия с "Дворцом Искусств"
void interactWithArtPalace(Player& player) {
    std::cout << "Вы вошли в Дворец Искусств. Здесь царит атмосфера творчества и вдохновения." << std::endl;
    std::cout << "Внутри вы видите великолепные картины, скульптуры и инсталляции, которые поражают воображение." << std::endl;

    std::cout << "Вы замечаете художника, который сидит на полу и рисует. Он выглядит расстроенным." << std::endl;
    std::cout << "Он поднимает голову и говорит: 'Я ищу вдохновение для своей новой картины, но не могу его найти.'" << std::endl;

    std::cout << "Что вы хотите сделать?" << std::endl;
    std::cout << "1. Поговорить с художником." << std::endl;
    std::cout << "2. Исследовать выставку." << std::endl;
    std::cout << "3. Вернуться на улицу." << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Вы подходите к художнику и начинаете разговор." << std::endl;
            std::cout << "'Я всегда черпаю вдохновение из окружающего мира,' - говорит он. 'Может быть, вы можете помочь мне найти его?'" << std::endl;
            std::cout << "'Если вы принесете мне что-то уникальное, я смогу завершить свою картину!'" << std::endl;
            // Здесь можно добавить квест на поиск уникального предмета
            break;
        case 2:
            std::cout << "Вы исследуете выставку и находите множество интересных произведений искусства." << std::endl;
            // Здесь можно добавить дополнительные события или квесты
            break;
        case 3:
            std::cout << "Вы решили вернуться на улицу." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
            interactWithArtPalace(player); // Повторный вызов для нового выбора
            break;
    }
}

// Функция для взаимодействия с "Башней Вдохновения"
void interactWithInspirationTower(Player& player) {
    std::cout << "Вы вошли в Башню Вдохновения. Здесь царит атмосфера креативности и новых идей." << std::endl;
    // Добавьте сюжет и действия для Башни Вдохновения
}

// Функция для взаимодействия с "Гранд Отелем"
void interactWithGrandHotel(Player& player) {
    std::cout << "Вы вошли в Гранд Отель. Здесь роскошь и комфорт на каждом шагу." << std::endl;
    // Добавьте сюжет и действия для Гранд Отеля
}

// Функция для взаимодействия с "Центром Науки"
void interactWithScienceCenter(Player& player) {
    std::cout << "Вы вошли в Центр Науки. Здесь проводятся удивительные эксперименты и исследования." << std::endl;
    // Добавьте сюжет и действия для Центра Науки
}

// Обновление функции interactWithArtDeco для добавления взаимодействия с зданиями
void interactWithArtDeco(Player& player) {
    std::cout << "Вы находитесь в районе арт-деко. Здесь пять великолепных зданий!" << std::endl;
    
    std::cout << "1. Здание Мира" << std::endl;
    std::cout << "2. Дворец Искусств" << std::endl;
    std::cout << "3. Башня Вдохновения" << std::endl;
    std::cout << "4. Гранд Отель" << std::endl;
    std::cout << "5. Центр Науки" << std::endl;

    int buildingChoice;
    std::cout << "Введите номер здания, в которое хотите войти: ";
    std::cin >> buildingChoice;

    switch (buildingChoice) {
        case 1:
            interactWithWorldBuilding(player); // Взаимодействие с "Зданием Мира"
            break;
        case 2:
            interactWithArtPalace(player); // Взаимодействие с "Дворцом Искусств"
            break;
        case 3:
            interactWithInspirationTower(player); // Взаимодействие с "Башней Вдохновения"
            break;
        case 4:
            interactWithGrandHotel(player); // Взаимодействие с "Гранд Отелем"
            break;
        case 5:
            interactWithScienceCenter(player); // Взаимодействие с "Центром Науки"
            break;
        default:
            std::cout << "Неверный выбор. Пожалуйста, попробуйте снова." << std::endl;
            break;
    }
}

int main() {
    Player player("Ученый");
    Quest quest1("Найти схему ", "Найти 20 летней давности схему постройки звездолета.");
    player.addQuest(quest1);

    player.showQuests();
    player.quests[0].completeQuest(); // Завершение первого квеста
    player.showQuests();

    int playerX = 2; // Начальная позиция игрока по оси X
    int playerY = 2; // Начальная позиция игрока по оси Y

    char command;
    while (true) {
        createMap(playerX, playerY); // Вызов функции для создания и отображения карты
        std::cout << "Введите команду (w/a/s/d для перемещения, q для выхода): ";
        std::cin >> command;

        // Обработка команд
        if (command == 'w' && playerY > 0) {
            playerY--; // Перемещение вверх
        } else if (command == 's' && playerY < 4) {
            playerY++; // Перемещение вниз
        } else if (command == 'a' && playerX > 0) {
            playerX--; // Перемещение влево
        } else if (command == 'd' && playerX < 4) {
            playerX++; // Перемещение вправо
        } else if (command == 'q') {
            break; // Выход из игры
        } else {
            std::cout << "Неверная команда или выход за пределы карты!" << std::endl;
        }

        // Проверка, находится ли игрок в Silex
        if (playerX == 4 && playerY == 0) {
            interactWithSilex(player); // Взаимодействие с локацией Silex
        }

        // Проверка, находится ли игрок в Сухой пещере
        if (playerX == 0 && playerY == 4) { // Предположим, что Сухая пещера находится в (0, 4)
            enterDryCave(player); // Вход в пещеру
        }

        // Проверка, находится ли игрок в Арт-деко
        if (playerX == 2 && playerY == 1) { // Предположим, что Арт-деко находится в (2, 1)
            interactWithArtDeco(player); // Взаимодействие с локацией Арт-деко
        }

        // Проверка, находится ли игрок в Дворце Искусств
        if (playerX == 2 && playerY == 1) { // Предположим, что Дворец Искусств находится в (2, 1)
            interactWithArtPalace(player); // Взаимодействие с "Дворцом Искусств"
        }

        // Проверка, если игрок собрал Silex-Cola
        if (playerX == 4 && playerY == 0) {
            player.quests.back().collect(); // Собираем бутылку Silex-Cola
        }
    }

    return 0;
}
