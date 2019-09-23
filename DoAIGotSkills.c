#include <stdio.h>
#include <stdbool.h>

#define SKILLS 9
#define PEOPLE 7

bool isSolution(bool selectedPeople[PEOPLE], bool data[PEOPLE][SKILLS]);
bool findSkills(int min, bool selectedPeople[PEOPLE], bool data[PEOPLE][SKILLS]);
bool dimensionHasSolution(int current, bool selectedPeople[PEOPLE], bool data[PEOPLE][SKILLS]);
void printNames(bool selectedPeople[PEOPLE], char names[PEOPLE][10]);

int main()
{
    char names[PEOPLE][10] = {"Kostas", "Petros", "Stathis", "Giorgos", "Arianna", "Lydia", "Alexia"};
    bool data[PEOPLE][SKILLS] = {
        {0, 0, 0, 1, 1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 1, 0, 0},
    };

    bool selected[PEOPLE] = {0};

    if (findSkills(PEOPLE, selected, data))
        printNames(selected, names);
    else
        printf("Could not find a solution.\n");

    getchar();
    return 0;
}

bool isSolution(bool selectedPeople[PEOPLE], bool data[PEOPLE][SKILLS])
{
    bool skillsFound[SKILLS] = {0};
    for (int i = 0; i < SKILLS; i++)
    {
        for (int j = 0; j < PEOPLE; j++)
        {
            if (selectedPeople[j] && data[j][i])
            {
                skillsFound[i] = true;
            }
        }
        if (!skillsFound[i])
            return false;
    }

    return true;
}

bool findSkills(int min, bool selectedPeople[PEOPLE], bool data[PEOPLE][SKILLS])
{
    if (min == 0)
        return false;

    if (!findSkills(min - 1, selectedPeople, data))
    {
        for (int i = 0; i < min; i++)
        {
            selectedPeople[i] = true;
        }
        for (int j = 0; j < PEOPLE; j++)
        {
            if (selectedPeople[j])
            {
                if (dimensionHasSolution(j, selectedPeople, data))
                    return true;
            }
        }
    }
    else
        return true;
}

bool dimensionHasSolution(int current, bool selectedPeople[PEOPLE], bool data[PEOPLE][SKILLS])
{
    selectedPeople[current] = false;

    for (int i = 0; i < PEOPLE; i++)
    {
        if (!selectedPeople[i])
        {
            selectedPeople[i] = true;
            if (isSolution(selectedPeople, data))
                return true;
            else
                selectedPeople[i] = false;
        }
    }
    selectedPeople[current] = true;
    return false;
}

void printNames(bool selectedPeople[PEOPLE], char names[PEOPLE][10])
{
    for (int i = 0; i < PEOPLE; i++)
    {
        if (selectedPeople[i])
        {
            printf("%s\n", names[i]);
        }
    }
}