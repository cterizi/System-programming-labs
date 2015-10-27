#include <stdio.h>

int main(){
  char *lexiko[] = {"associate's degree","bachelor's degree","campus","community college","course","credit","degree","dorm","enroll","exam","faculty","fail","financial aid","fraternity","GPA","graduate","instructor","lecture","major","master's degree","matriculate","notebook","notes","pass","PhD","postgraduate","prerequisite","professor","quiz"};
  printf("%s\n", *(lexiko + 1));
  
  return 0;
}