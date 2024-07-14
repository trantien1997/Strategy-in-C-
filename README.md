Mô hình “Strategy” (hay còn gọi là mẫu chiến lược) là một mẫu thiết kế trong lập trình, giúp bạn trừu tượng hóa các hành vi (behavior) của một đối tượng bằng cách đưa ra các cài đặt vào các lớp khác nhau. 
Điểm chính của mô hình này là cho phép thay đổi hành vi của một đối tượng tại thời điểm chạy mà không ảnh hưởng đến các đối tượng khác.

Cách hoạt động của mô hình “Strategy”:

Bạn tạo một lớp trừu tượng (thường gọi là Strategy) để đại diện cho một hành vi cụ thể (ví dụ: thuật toán sắp xếp, cách xử lý dữ liệu, etc.).
Các lớp con kế thừa từ Strategy triển khai các cài đặt cụ thể cho hành vi đó.
Đối tượng sử dụng hành vi này giữ một con trỏ đến lớp Strategy, và tại thời điểm chạy, nó có thể thay đổi hành vi bằng cách thay đổi con trỏ đó.
Ví dụ về mô hình “Strategy” trong C++ có thể là việc chọn cách sắp xếp một danh sách (sắp xếp theo tên, theo giá trị, etc.) hoặc cách xử lý dữ liệu (nén, mã hóa, etc.). 
Bằng cách sử dụng mô hình này, bạn có thể linh hoạt thay đổi hành vi của đối tượng mà không cần thay đổi cấu trúc của nó.
