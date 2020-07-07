# Trại hè tin học 2020

Một số file được dùng trong trại hè.

## Cách tự sinh test

Trong mỗi folder của bài (tạm gọi tên bài là `name`), sẽ có 2 file là `name.cpp` và `name_gen.cpp`. Để sinh test, trước tiên bạn cần compile ra 2 file là `name.exe` và `name_gen.exe`. Sau đó chỉ việc chạy file `name_gen.exe` để tự sinh test.

**Trình sinh test sẽ sinh test một cách ngẫu nhiên dựa vào thời gian hiện tại của máy tinh**, vì vậy nên mỗi lần chạy sẽ sinh ra một bộ test khác nhau

Do trình sinh sử dụng các file nên `exe` nên có thể code sẽ không hoạt động trên các hệ điều hành không phải Windows. Nếu bạn sử dụng các hệ điều hành khác (Linux, MacOS, ...) thì có thể cần phải sửa lại code sinh test.

## Một vài kiến thức / kĩ thuật vặt cần biết

- C++ có hàm ước chung nhỏ nhất được viết sẵn

```cpp
int a, b;
cout << __gcd(a, b);
```

- Cách duyệt qua các bit được bật của một số

```cpp
int n;
for (int k=0;k<=(int)log2(n);k++){
    if ((n>>k)&1){
        // bit k được bật
    }
}
```

- Định lý Fermat bé

```
Nếu p là số nguyên tố và gcd(a,p) = 1, thì
1 = a^(p-1) mod p 
1/a = a^(p-2) mod p
```

- Tính lũy thừa nhanh (với modulo khoảng 10^9 trở xuống)

```cpp
int MOD = 123456789;
// a nên nhỏ hơn MOD trước khi dùng hàm
int pow(int a,int p){   
    if (p == 0) return 1;
    if (p == 1) return a;
    int t = pow(a, p/2);
    return 1ll * t * t % MOD * pow(a, p%2); // 1ll là số 1 kiểu long long
}
```
