LỚP KẾ THỪA
    ios -> istream, ostream -> iostream
cin là đối tượng lớp istream

KÍ HIỆU:
    '\n': Xuống dòng <enter>, không được nhập \n vào input stream
    '\0': Kí tự kết thúc của mảng kí tự 
    
------------------------------------------------------------------------------------------------------
Nhập dữ liệu bằng đối tượng cin:
    int a;
    cin >> a;
    
1. cin sẽ bỏ đi kí tự khoảng trắng cho đến khi gặp được kí số: 
    Example:   "           10"   =>    a = 10
        
2. cin sẽ ngắt số nếu gặp khoảng trắng:
    Example:   "100 200"   =>    a = 100

3. cin sẽ bỏ qua enter:
    Example:   "\n 30"     =>    a = 30
        
4. cin sẽ bỏ qua tab:
    Example:   "\t 40"     =>    a = 40

5. sẽ dừng lại nếu đọc kiểu dữ liệu không giống với biến
    Example:    "aaa 3"    =>    a = 0

6. sau khi lấy được giá trị số, dừng đọc khi gặp khoảng trắng:
    Example:    " 30    40"     => a = 30

7. Đối tượng cin sẽ lưu chuỗi nhập từ bàn phím vào input stream      
        int a, b;
        cin >> a >> b;  // "1 2\n"
        cout << a << " " << b << endl;  // "1 2"
        
        int a, b;
        cin >> a >> b;  // "a 3\n" Thất bại khi cin tại a dẫn đến "a 3\n" vẫn còn trong input stream
        cout << a << " " << b << endl;  // "0 6422356"

8. Nhập mảng kí tự bằng đối tượng cin sẽ bị dừng nếu gặp khoảng trắng
    char str[10];
    cin >> str;
    cout << str;
    
    Example:    "123 567\n"     str = "123\0"   input = ""
    
    char str1[10];
    cin >> str1;    // "123 567\n"  str1 = "123\0"    input = " 567\n"
    char str2[10];  
    cin >> str2;    // str2 = "567\0"   input = "\n"
    cout << str1 << " " << str2 << endl;    //  "123 567"
        
------------------------------------------------------------------------------------------------------
Sử dụng cin.clear() xóa bỏ trạng thái lỗi:
    Lấy dữ liệu từ biểu thức toán học: 
    Example: 3 * 4  => int a = 3, int b = 4, char symbol = '*'
      
    int a, b;
    char symbol;
    cin >> a;       // a = 3
    cin.clear();    // giữ lại input stream không xóa,          input stream = " * 4"
    cin >> symbol;  // bỏ qua kí tự trắng để symbol = '*',      input stream = " 4"
    cin.clear();    // giữ lại input stream không xóa,          input stream = " 4"
    cin >> b;       // bỏ qua kí tự trắng để b = 4,             input stream = ""

------------------------------------------------------------------------------------------------------
Nhập từ bàn phím LẤY RA KÍ TỰ ĐẦU TIÊN, trả về mã ascii của kí tự đó bằng int cin.get()  
    char a;
    a = cin.get();
    cout << a;
    
    Example:    "    abc "  =>  a = ' '

1. Tiếp tục lấy từ input stream
    char a, b;
    a = cin.get();  // a<enter>
    b = cin.get();  // \n
    cout << a << " " << (b == '\n') << endl;    // a 1

2. cin.get() sẽ lưu chuỗi vào input stream và lấy kí tự đầu tiên
   char a;
   cin.get();       // "abc\n"
   a = cin.get();   // store 'a' to a, input stream = 'bc\n'
   cout << a;       // 'b'

3. istream& cin.get(char &ch) Không giá trị trả về nhưng LẤY RA KÍ TỰ ĐẦU TIÊN cho biến ch 
    char c;
    cin.get(c);     // "abc\n" -> c = 'a'
    cout << c;      // 'a'
    
    char c, d;
    cin.get(c).get(d);              // "abc\n" -> c = 'a', d = 'b'
    cout << c << " " << d << endl;  // "a b"

4. istream& cin.get(char* str, int n, char delim = ‘\n’) Không giá trị trả về nhưng LẤY RA CHUỖI KÍ TỰ kể cả khoảng trắng, dừng lại khi gặp kí tự '\n' = delim
    char str[10];
    cin.get(str, 10, '\n');     // Chỉ lấy n - 1 kí tự tức 9 kí tự vì ô cuối là '\0',   "1234 6789**\n" -> "1234 6789" để lại input = "**\n"
    cout << str;                // "1234 6789"
    
    char str[10];
    cin.get(str, 10, '\n');     // "abc\n"      str = "abc\0"   input = "\n"
    cout << str;                // "abc"

    char str[10];
    cin.get(str, 10);           // "abc\n"      str = "abc\0"   input = "\n"    Tự hiểu gặp kí tự '\n' sẽ dừng
    cout << str << " " << (cin.get() == '\n');                // "abc 1"
    
5.  istream& cin.getline(char* str, int n, char delim = ‘\n’) Không giá trị trả về nhưng LẤY RA CHUỖI KÍ TỰ kể cả khoảng trắng, dừng lại khi gặp kí tự '\n' = delim
    char str[10];
    cin.getline(str, 10);       // "abc\n" và được nhập tiếp "a\n" bởi vì input = "" do hàm getline sẽ bỏ kí tự '\n' làm input trống cho phép nhập mới, str = "abc\0"
    cout << str << " " << (cin.get() == '\n');  // "abc 0" 
    
    char str1[10], str2[10];
    cin.getline(str1, 10).getline(str2, 10);    // "ab\n" và "cd\n"     str1 = "ab\0"   str2 = "cd\0"  
    cout << str1 << " " << str2 << endl;        // "ab cd"

6. 
    
    
