------------------------------------------------------------------------------------------------------
Nhập dữ liệu bằng đối tượng cin:
    int a;
    cin >> a;
- cin sẽ bỏ đi kí tự khoảng trắng cho đến khi gặp được kí số: 
    Example:  "           10"   =>    a = 10
- cin sẽ ngắt số nếu gặp khoảng trắng:
    Example:  "100 200"   =>    a = 100
        
------------------------------------------------------------------------------------------------------
Sử dụng cin.clear() xóa bỏ trạng thái lỗi:
lấy dữ liệu từ biểu thức toán học: 
  Example: 3 * 4  => int a = 3, int b = 4, char symbol = '*'
  Code C++:
    int a, b;
    char symbol;
    cin >> a;       // a = 3
    cin.clear();    // giữ lại input stream không xóa,          input stream = " * 4"
    cin >> symbol;  // bỏ qua kí tự trắng để symbol = '*',      input stream = " 4"
    cin.clear();    // giữ lại input stream không xóa,          input stream = " 4"
    cin >> b;       // bỏ qua kí tự trắng để b = 4,             input stream = ""
