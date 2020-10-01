#include"house.cpp"
#include"node.cpp"
#include<cstdio>
#include"SpecialPrint.cpp"


// this cpp will display the Node, including the color and the position of player
void PrintMap() {       // 记得添加CNode数组
    printf("\n");

    // 1 line
    PrintOutline(0, 1, 0, 1);
    for(int i = 1; i <= 10; i++) {
        PrintOutline(0, 0, 1, 1, 5);
        PrintOutline(0, 1, 1, 1);
    }
    PrintOutline(0, 0, 1, 1, 5);
    PrintOutline(0, 1, 1, 0, 1, 1);

    // 2 line
    PrintOutline(1, 1, 0, 0);
    for(int i = 1; i <= 11; i++) {
        printf("     ");      // 以后填Node信息
        PrintOutline(1, 1, 0, 0);
    }
    printf("\n");

    // 3 line
    PrintOutline(1, 1, 0, 0);
    for(int i = 1; i <= 11; i++) {
        printf("     ");      // 以后填Node信息
        PrintOutline(1, 1, 0, 0);
    }
    printf("\n");

    // 4 line
    PrintOutline(1, 1, 0, 1);
    PrintOutline(0, 0, 1, 1, 5);
    PrintOutline(1, 1, 1, 1);
    for(int i = 1; i <= 8; i++) {
        PrintOutline(0, 0, 1, 1, 5);
        PrintOutline(1, 0, 1, 1);
    }
    PrintOutline(0, 0, 1, 1, 5);
    PrintOutline(1, 1, 1, 1);
    PrintOutline(0, 0, 1, 1, 5);
    PrintOutline(1, 1 ,1, 0, 1, 1);

    // 5 ~n line
    for(int i = 1; i <= 8; i++) {
       PrintOutline(1, 1, 0, 0);
       printf("     ");
       PrintOutline(1, 1, 0, 0);
       for(int i = 1; i <= 53; i++) {
            printf(" ");
        }
        PrintOutline(1, 1, 0, 0);
        printf("     ");
        PrintOutline(1, 1, 0, 0, 1, 1);

        PrintOutline(1, 1, 0, 0);
        printf("     ");
        PrintOutline(1, 1, 0, 0);
        for(int i = 1; i <= 53; i++) {
            printf(" ");
        }
        PrintOutline(1, 1, 0, 0);
        printf("     ");
        PrintOutline(1, 1, 0, 0, 1, 1);

        PrintOutline(1, 1, 0, 1);
        PrintOutline(0, 0, 1, 1 , 5);
        PrintOutline(1, 1, 1, 0);
        for(int i = 1; i <= 53; i++) {
            printf(" ");
        }
        PrintOutline(1, 1, 0, 1);
        PrintOutline(0, 0, 1, 1 , 5);
        PrintOutline(1, 1, 1, 0, 1, 1);
    }

    // n~last
    PrintOutline(1, 1, 0, 0);
    printf("     ");
    PrintOutline(1, 1, 0, 0);
    for(int i = 1; i <= 53; i++) {
        printf(" ");
    }
    PrintOutline(1, 1, 0, 0);
    printf("     ");
    PrintOutline(1, 1, 0, 0, 1, 1);

    PrintOutline(1, 1, 0, 0);
    printf("     ");
    PrintOutline(1, 1, 0, 0);
    for(int i = 1; i <= 53; i++) {
        printf(" ");
    }
    PrintOutline(1, 1, 0, 0);
    printf("     ");
    PrintOutline(1, 1, 0, 0, 1, 1);

    PrintOutline(1, 1, 0, 1);
    PrintOutline(0, 0, 1, 1, 5);
    PrintOutline(1, 1, 1, 1);
    for(int i = 1; i <= 8; i++) {
        PrintOutline(0, 0, 1, 1, 5);
        PrintOutline(0, 1, 1, 1);
    }
    PrintOutline(0, 0, 1, 1, 5);
    PrintOutline(1, 1, 1, 1);
    PrintOutline(0, 0, 1, 1, 5);
    PrintOutline(1, 1 ,1, 0, 1, 1);

    PrintOutline(1, 1, 0, 0);
    for(int i = 1; i <= 11; i++) {
        printf("     ");      // 以后填Node信息
        PrintOutline(1, 1, 0, 0);
    }
    printf("\n");

    // 3 line
    PrintOutline(1, 1, 0, 0);
    for(int i = 1; i <= 11; i++) {
        printf("     ");      // 以后填Node信息
        PrintOutline(1, 1, 0, 0);
    }
    printf("\n");

    PrintOutline(1, 0, 0, 1);
    for(int i = 1; i <= 10; i++) {
        PrintOutline(0, 0, 1, 1, 5);
        PrintOutline(1, 0, 1, 1);
    }
    PrintOutline(0, 0, 1, 1, 5);
    PrintOutline(1, 0, 1, 0, 1, 1);
}

    
