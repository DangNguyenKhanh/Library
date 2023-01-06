Cách lấy khoảng trắng của chuỗi:
  #include<stdio.h>
  void main()
  {
      char s[100];
      scanf("%[^\n]s", s);
      printf("%s", s);
  }
