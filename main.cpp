#include <iostream>
#include <string>
#include <vector>

class Quest {
public:
    std::string title;
    std::string description;
    bool isCompleted;
    int requiredAmount; // ������⢮, ����室���� ��� �����襭�� �����
    int collectedAmount; // ������⢮, ᮡ࠭��� ��ப��

    Quest(std::string t, std::string d, int reqAmount = 0) 
        : title(t), description(d), isCompleted(false), requiredAmount(reqAmount), collectedAmount(0) {}

    void collect() {
        if (!isCompleted && collectedAmount < requiredAmount) {
            collectedAmount++;
            std::cout << "�� ᮡࠫ� ���뫪� Silex-Cola! �ᥣ�: " << collectedAmount << "/" << requiredAmount << std::endl;
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

// ���⨯ �㭪樨 ��� ����������⢨� � �ନ����� ࠡ�⭨��
void interactWithTerminal();

// �㭪�� ��� ᮧ����� � �⮡ࠦ���� ����� 5x5 � ������祭��� ���⮯�������� ��ப� � ����樨 Silex
void createMap(int playerX, int playerY) {
    const int size = 5;
    char map[size][size];

    // ���������� ����� ᨬ������
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            map[i][j] = '.'; // '.' ������砥� ������ �����
        }
    }

    // ��⠭���� ���⮯�������� ��ப�
    map[playerY][playerX] = 'Y'; // 'Y' ������砥� ���⮯�������� ��ப�

    // ��⠭���� ����樨 Silex
    int silexX = 4; // ���न���� Silex �� �� X
    int silexY = 0; // ���न���� Silex �� �� Y
    map[silexY][silexX] = 'S'; // 'S' ������砥� ������ Silex

    // �⮡ࠦ���� �����
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << map[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

// �㭪�� ��� ����������⢨� � ����樥� Silex
void interactWithSilex(Player& player) {
    std::cout << "�� ��室���� � Silex. ����� �த����� ����஢�� Silex-Cola!" << std::endl;
    std::cout << "��-� ������: '�� ����஢�� - ���訩 ᯮᮡ �⮫��� �����!'" << std::endl;

    // ���������� �����, �易����� � Silex-Cola
    Quest silexColaQuest("���� Silex-Cola", "�ਭ��� Silex-Cola ��� ���⭮�� ��⥫�.", 5);
    player.addQuest(silexColaQuest);
    std::cout << "�� ����稫� ���� �����: " << silexColaQuest.title << std::endl;

    // ����������⢨� � �ନ�����
    char terminalCommand;
    std::cout << "���� ������ �ନ��� ࠡ�⭨��? (y/n): ";
    std::cin >> terminalCommand;

    if (terminalCommand == 'y') {
        interactWithTerminal();
    }
}

// �㭪�� ��� ����������⢨� � �ନ����� ࠡ�⭨��
void interactWithTerminal() {
    std::cout << "��ନ��� ࠡ�⭨��: " << std::endl;
    std::cout << "��������! ����� ����� �뫨 ��襭� �� 䠡ਪ�!" << std::endl;
    std::cout << "������ ����᪠�. ����⭨�� ������ ���஢����� ����������!" << std::endl;
    std::cout << "�� ����﫨 ��� � 業�ࠫ�� ��ᮬ. ��������, ��⠢����� � ���⨨!" << std::endl;
    std::cout << "�� ���뢠�� � Silex-Cola, ��� ����� ᯠ�� ��� �����!" << std::endl;
}

int main() {
    Player player("�祭�");
    Quest quest1("���� �奬� ", "���� 20 ��⭥� ������� �奬� ����ன�� ���������.");
    player.addQuest(quest1);

    player.showQuests();
    player.quests[0].completeQuest(); // �����襭�� ��ࢮ�� �����
    player.showQuests();

    int playerX = 2; // ��砫쭠� ������ ��ப� �� �� X
    int playerY = 2; // ��砫쭠� ������ ��ப� �� �� Y

    char command;
    while (true) {
        createMap(playerX, playerY); // �맮� �㭪樨 ��� ᮧ����� � �⮡ࠦ���� �����
        std::cout << "������ ������� (w/a/s/d ��� ��६�饭��, q ��� ��室�): ";
        std::cin >> command;

        // ��ࠡ�⪠ ������
        if (command == 'w' && playerY > 0) {
            playerY--; // ��६�饭�� �����
        } else if (command == 's' && playerY < 4) {
            playerY++; // ��६�饭�� ����
        } else if (command == 'a' && playerX > 0) {
            playerX--; // ��६�饭�� �����
        } else if (command == 'd' && playerX < 4) {
            playerX++; // ��६�饭�� ��ࠢ�
        } else if (command == 'q') {
            break; // ��室 �� ����
        } else {
            std::cout << "����ୠ� ������� ��� ��室 �� �।��� �����!" << std::endl;
        }

        // �஢�ઠ, ��室���� �� ��ப � Silex
        if (playerX == 4 && playerY == 0) {
            interactWithSilex(player); // ����������⢨� � ����樥� Silex
        }

        // �஢�ઠ, �᫨ ��ப ᮡࠫ Silex-Cola
        if (playerX == 4 && playerY == 0) {
            player.quests.back().collect(); // ����ࠥ� ���뫪� Silex-Cola
        }
    }

    return 0;
}