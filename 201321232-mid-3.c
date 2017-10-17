#include <stdio.h>
#include <string.h>

int input (char word[50]);
void print_arr (char word[50]);
void swap (char word1[50], char word2[50]);

int main (void){

    char word1[50];
    char word2[50];
    char word3[50];

    printf("단어 입력: ");
    if(!input(word1)){  //input함수의 리턴 값을 이용해 return값이 0이면 EOF입력이 들어왔다는 것을 구분
        //!을 이용해 역으로 변경하면 1, 조건을 만족시키므로 프로그램 종료
        return 0;
    }
    printf("정렬 된 단어: ");
    print_arr(word1);   //총 단어의 갯수가 1개이므로 정렬과정을 생략
    putchar('\n');
    printf("현재까지의 문자열: ");
    print_arr(word1);
    putchar('\n');

    //두 번째 단어
    printf("단어 입력: ");
    if(!input(word2)){  //input함수의 리턴 값을 이용해 return값이 0이면 EOF입력이 들어왔다는 것을 구분
        //!을 이용해 역으로 변경하면 1, 조건을 만족시키므로 프로그램 종료
        return 0;
    }
    int r;  //정렬 결과를 저장할 변수(strcmp의 반환값)
    r = strcmp(word1,word2);
    printf("정렬 된 단어: ");
    if(r > 0){  //반환 값이 0보다 클 경우, 두 번째 입력받은 단어가 사전순으로는 앞에 위치함을 의미
        print_arr(word2);   //word2 문자열을 먼저 출력해줌
        print_arr(word1);
    }
    else{   //반환값이 0이거나 0보다 작을 경우는 출력순서를 변경할 필요가 없으므로 입력순으로 출력
        print_arr(word1);
        print_arr(word2);
    }
    putchar('\n');
    printf("현재까지의 문자열: ");
    print_arr(word1);
    print_arr(word2);
    putchar('\n');

    //세 번째 단어
    printf("단어 입력: ");
    if(!input(word3)){  //input함수의 리턴 값을 이용해 return값이 0이면 EOF입력이 들어왔다는 것을 구분
        //!을 이용해 역으로 변경하면 1, 조건을 만족시키므로 프로그램 종료
        return 0;
    }
    printf("정렬 된 단어: ");
    char copy1[50];     //배열은 복사해 copy로 저장
    char copy2[50];     //사전순과 입력받은 순 두 가지를 출력해야하므로 전용 배열을 생성
    char copy3[50];
    strcpy(copy1,word1);
    strcpy(copy2,word2);
    strcpy(copy3,word3);

    if(strcmp(copy1,copy2) > 0){    //뒤에 있는 문자열을 앞 단어와 교환해야 하는 경우만 교환
        swap(copy1,copy2);          //입력순으로 저장되어있는 단어들을 사전순으로 정렬
    }
    if(strcmp(copy1,copy3) > 0){    //(1,2),(1,3)비교로 맨 먼저 나와야하는 copy1을 고정
        swap(copy1,copy3);          //(2,3)비교를 통해 2,3번째 자리를 지정
    }
    if(strcmp(copy2,copy3) > 0){
        swap(copy2,copy3);
    }
    print_arr(copy1);           //사전순 출력
    print_arr(copy2);
    print_arr(copy3);
    putchar('\n');
    printf("현재까지의 문자열: ");
    print_arr(word1);
    print_arr(word2);
    print_arr(word3);
    putchar('\n');

    return 0;
}

int input (char word[50]){  //문자열 입력받아오는 함수
    if(gets(word)== 0){     //반환값이 0이면 EOF
        putchar('\n');
        return 0;
    }
    else return 1;
}

void print_arr (char word[50]){     //문자열 배열 출력함수
    printf("%s ",word);
}
void swap (char word1[50], char word2[50]){

    char temp[50];      //사전순 배열에서 순서를 교환할 때 쓰이는 중간 문자열
    if(strcmp(word1,word2) > 0){    //뒤에 있는 문자열을 앞 단어와 교환해야 하는 경우만 교환
        strcpy(temp,word1);         //입력순으로 저장되어있는 단어들을 사전순으로 정렬
        strcpy(word1,word2);
        strcpy(word2,temp);
    }
}
