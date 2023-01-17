cout là đối tượng của ostream

------------------------------------------------------------------------
Qua định độ rộng: cout.width(int n = 0) Thiết lập độ rộng, trả về độ rộng trước đó, áp dùng cho 1 lần xuất 
1. Độ rộng là 10 và canh lề trái:
  #include<iostream>
  using namespace std;
  int main()
  {
      cout.width(10);
      cout << left;
      cout << "ID";

      cout.width(10);
      cout << left;
      cout << "Name";
  }

2. Hàm quy định độ rộng
  <iomanip>: cout << setw(int n) << a;

------------------------------------------------------------------------
Kí tự độn (ios): cout.fill(char c = ‘ ’)

------------------------------------------------------------------------
Độ chính xác – giới hạn chữ số: cout.precision(int n);

1. int cout.precision(): Trả về độ chính xác hiện tại

2. int cout.precision(int n); Thiết lập độ chính xác, trả về độ chính xác trước đó, hiệu lực 
cho tới khi gặp một câu lệnh thiết lập độ chính xác mớ, ngoài ra còn làm tròn 

3. Hàm setprecision <iomanip>: cout << setprecision(int n) << a;

4. Từ sau dấu phẩy sẽ cố định theo setprecision: cout.setf(ios::fixed);

------------------------------------------------------------------------
Căn lề 
1. cout.setf(ios::right)	: Căn lề phải, trái bị dư

2. cout.setf(ios::left)	: Căn lề trái,  phải bị dư




