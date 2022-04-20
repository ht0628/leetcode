## C++

### C++11 库函数

```c++
1.string类型转换
    #include <string>
    std::to_string(int/long/float.......)
    int val = std::stoi(str)
    long val = std::stol(str)
    float val = std::stof(str)
2.char*字符串类型转换
    atoi: 将字符串转换为 int
    atol: 将字符串转换为 long
    atoll:将字符串转换为 long long
    atof: 将字符串转换为浮点数
3.判断某个字符型是否是数字
    isdigit(c)
4.反转可迭代数据结构
    #include <algorithm>
    reverse(res.begin(),res.end());
5.排序函数
    #include <algorithm>
    void sort (RandomAccessIterator first, RandomAccessIterator last);
 	std::vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };
	std::sort(myvector.begin(), myvector.begin() + 4);
6.查找函数
    std::find(v.begin(), v.end(), key) != v.end()
```





### string

基本操作

```c++
#include <iostream>
#include <string>
using namespace std;

/* 创建 */
	//1.采用构造函数
    string s1();  				//s1 = ""
    string s2("Hello");  		//s2 = "Hello"
    string s3(4, 'K');  		//s3 = "KKKK"
    string s4("12345", 1, 3);  	//s4 = "234"，即 "12345" 的从下标 1 开始，长度为 3 的子串

    //2.赋值型初始化
	string s1,s2,s3;
    s1 = "1234";
    s2 = s1;

	//3.API-assign初始化
	s3.assign(s1);				//s3 = s1
	s3.assign(s1,1,2);			//s3 = 23
	s3.assign(4,'K')			//s3 = "KKKK"
    s3.assign("abcde",2,3)		//s3 = "cde"
	
/* 增 */
	//1.使用"+"或者"+="拼接或添加到末尾
    string s1 = "first ";
    string s2 = "second ";
    char *s3 = "third ";
    char s4[] = "fourth ";
    char ch = '@';
    string s5 = s1 + s2;
    string s6 = s1 + s3;
    string s7 = s1 + s4;
    string s8 = s1 + ch;

	//2.API - string &append(const char *s)
	//  把字符串s连接到当前字符串结尾
	string s1("123"), s2("abc");
    s1.append(s2);  			//s1 = "123abc"
    s1.append(s2, 1, 2);  		//s1 = "123abcbc"
    s1.append(3, 'K');  		//s1 = "123abcbcKKK"
    s1.append("ABCDE", 2, 3);  	//s1 = "123abcbcKKKCDE"，添加 "ABCDE" 的子串(2, 3)

	//3.API - void push_back(char c)
	//  功能介绍：当前字符串尾部加一个字符c
	string s1("123");
    s1.push_back('4');			//s1 = "1234"

	//4.API - string &insert(int p,const string &s)
	//  在p位置插入字符串s
    string s1("Limitless"), s2("00");
    s1.insert(2, "123");  				//在下标 2 处插入字符串"123"，s1 = "Li123mitless"
    s1.insert(3, s2);  					//在下标 2 处插入 s2 , s1 = "Li10023mitless"
    s1.insert(3, 5, 'X');  				//在下标 3 处插入 5 个 'X'，s1 = "Li1XXXXX0023mitless"
	

/* 删 */
	//1.API - string &erase(int p, int n)
	//  删除p开始的n个字符，返回修改后的字符串。
    string s1("Real Steel");
    s1.erase(1, 3);  		//删除子串(1, 3)，此后 s1 = "R Steel"
    s1.erase(5);  			//删除下标5及其后面的所有字符，此后 s1 = "R Ste"

/* 查 */
	//1.查字符串长度
	s.length();
	s.size();
	
	//2.提取字串
	//API - string substr(int pos, int n ) 
	//返回pos开始的n个字符组成的字符串
	string s1 = "this is ok";
    string s2 = s1.substr(2, 4);  	// s2 = "is i"
    s2 = s1.substr(2);  			// s2 = "is is ok"

	//3.查找字串或字符
	以下函数的返回值都是字串或字符在string对象字符中的位置(即下标)。如果查不到，则返回string::npos。
    find：从前往后查找子串或字符出现的位置。
    rfind：从后往前查找子串或字符出现的位置。
    find_first_of：从前往后查找何处出现另一个字符串中包含的字符。例如：
    s1.find_first_of("abc");  //查找s1中第一次出现"abc"中任一字符的位置
    find_last_of：从后往前查找何处出现另一个字符串中包含的字符。
    find_first_not_of：从前往后查找何处出现另一个字符串中没有包含的字符。
    find_last_not_of：从后往前查找何处出现另一个字符串中没有包含的字符。
        
	#include <iostream>
    #include <string>
    using namespace std;
    int main()
    {
        string s1("Source Code");
        int n;
        if ((n = s1.find('u')) != string::npos) 					//查找 u 出现的位置
            cout << "1) " << n << "," << s1.substr(n) << endl;  	//输出 l)2,urce Code

        if ((n = s1.find("Source", 3)) == string::npos)				//从下标3开始查找"Source"，找不到
            cout << "2) " << "Not Found" << endl;  					//输出 2) Not Found
        
        if ((n = s1.find("Co")) != string::npos)					//查找子串"Co"。能找到，返回"Co"的位置
            cout << "3) " << n << ", " << s1.substr(n) << endl;		//输出 3) 7, Code
        
        if ((n = s1.find_first_of("ceo")) != string::npos)			//查找第一次出现或 'c'、'e'或'o'的位置
            cout << "4) " << n << ", " << s1.substr(n) << endl; 	//输出 4) l, ource Code
        
        if ((n = s1.find_last_of('e')) != string::npos)				//查找最后一个 'e' 的位置
            cout << "5) " << n << ", " << s1.substr(n) << endl; 	//输出 5) 10, e
        
        if ((n = s1.find_first_not_of("eou", 1)) != string::npos)	//从下标1开始查找第一次出现非 'e'、'o' 或 'u' 字符的位置
			cout << "6) " << n << ", " << s1.substr(n) << endl;		//输出 6) 3, rce Code
        return 0;
    }

/* 改 */
	//1.operator[]
	s[i] = xx
    
    //2.交换两个string对象的内容
    //API - void swap(string &s2)
    //交换当前字符串与s2的值
    string s1("West”), s2("East");
	s1.swap(s2);  // s1 = "East"，s2 = "West"
              
    //3.替换
    //API - string &replace(int p, int n, const char *s)
    //删除从p开始的n个字符，然后在p处插入字符串s
	string s1("Real Steel");
    s1.replace(1, 3, "123456", 2, 4);  	//用 "123456" 的子串(2,4) 替换 s1 的子串(1,3)
    cout << s1 << endl;  				//输出 R3456 Steel
    string s2("Harry Potter");
    s2.replace(2, 3, 5, '0');  			//用 5 个 '0' 替换子串(2,3)
    cout << s2 << endl;  				//输出 HaOOOOO Potter
    int n = s2.find("OOOOO");  			//查找子串 "00000" 的位置，n=2
    s2.replace(n, 5, "XXX");  			//将子串(n,5)替换为"XXX"
    cout << s2 < < endl;  				//输出 HaXXX Potter

/* 比较 */
	//1.可以用 <、<=、==、!=、>=、> 运算符比较
    
    //2.API-compare
    string s1("hello"), s2("hello, world");
    int n = s1.compare(s2);
    n = s1.compare(1, 2, s2, 0, 3);  		//比较s1的子串 (1,2) 和s2的子串 (0,3)
    n = s1.compare(0, 2, s2);  				//比较s1的子串 (0,2) 和 s2
    n = s1.compare("Hello");
    n = s1.compare(1, 2, "Hello");  		//比较 s1 的子串(1,2)和"Hello”
    n = s1.compare(1, 2, "Hello", 1, 2);  	//比较 s1 的子串(1,2)和 "Hello" 的子串(1,2)
        
/* 输入输出 */
    int main(){
        string s;
        cin>>s;  //输入字符串
        cout<<s<<endl;  //输出字符串
        return 0;
    }

/* 转换成C风格 */
string path = "D:\\demo.txt";
FILE *fp = fopen(path.c_str(), "rt");

```



## STL容器常用API

### vector

基本操作

```c++
#include <vector>
using namespace std;

/* 创建 */
//1.仅声名 不分配内存空间 适用于动态添加情况
vector<int> list;

//2.拷贝创建
vector<int> list2(list1)
vector<int> list2 = list1
vector<int> list2(list1.begin()+1,list1.begin()+3)

//3.赋初值创建
vector<int> list = {0,1,2,3};
vector<int> list{0,1,2,3};

vector<int> list(4);	//默认为0
vector<int> list(4,1)	//默认为1

//4.构造矩阵
vector<vector<int>> matrix(3,vector<int>(4))			//高频：构造二维矩阵
vector<int>value1(3)								//高频：构造一维矩阵
   

/* 增 */
push_back(ele);										//尾部插入
insert(const_iterator pos, int count, ele);			//迭代器指向位置pos插入count个元素ele.
/* 删 */
pop_back();											//尾部删除
erase(const_iterator start, const_iterator end);	//删除迭代器从start到end之间的元素
erase(const_iterator pos);							//删除迭代器指向的元素
clear();											//删除容器中所有元素
/* 查 */
operator[]											//返回索引idx所指的数据
at(int idx); 										//返回索引idx所指的数据
front();											//返回容器中第一个数据元素
back();												//返回容器中最后一个数据元素
size();												//返回容器中元素的个数
empty();											//判断容器是否为空
capacity();											//容器的容量
/* 改 */
resize(int num);									//重新指定容器的长度为num,默认填充。
resize(int num,ele);								//重新指定容器的长度为num,ele填充。
reserve(int len);									//容器预留len个元素长度，预留位置不初始化，												      元素不可访问。
/* 遍历 */
vector<char>value;
...
for (auto i = value.begin(); i < value.end(); i++) {
    cout << *i << " ";
}
```



### unordered_set

基本操作

```c++
#include <unordered_set>
using namespace std;

/* 创建 */
unordered_set<string> uset;
unordered_set<string> uset{"http://c.biancheng.net/c/",
                           "http://c.biancheng.net/java/",
                           "http://c.biancheng.net/linux/"};
unordered_set<string> uset2(uset) //拷贝式创建
/* 增 */
uset.insert("xx")
uset.emplace("xx") //比insert效率高
/* 删 */
uset.erase("xx")
uset.clear() //清空
/* 查 */
empty()    //为空返回true
size()     //返回元素个数
find(key)  //查找以值为 key 的元素，如果找到，则返回一个指向该元素的正向迭代器；反之，则返回一个指向容器中最后一个元素之后位置的迭代器（如果 end() 方法返回的迭代器）。
count(key) //在容器中查找值为 key 的元素的个数。
/* 改 */
/* 遍历 */
for (auto iter = uset.begin(); iter != uset.end(); ++iter) {
	cout << *iter << endl;
}
```



### unordered_map

```c++
#include <unordered_map>
using namespace std;

/* 创建 */
unordered_map<string,string> umap;
unordered_map<string, string> umap{
    {"Python教程","http://c.biancheng.net/python/"},
    {"Java教程","http://c.biancheng.net/java/"},
    {"Linux教程","http://c.biancheng.net/linux/"} };
unordered_map<string,string> umap2(umap) //拷贝式创建
/* 增 */
umap.insert("xx","xx")
umap.emplace("xx","xx") //比insert效率高
/* 删 */
umap.erase("xx")
umap.clear() //清空
/* 查 */
umap[key]
umap.at(key)
umap.empty()    //为空返回true
umap.size()     //返回元素个数
umap.find(key)  //查找以值为 key 的元素，如果找到，则返回一个指向该元素的正向迭代器；反之，则返回一个指向容器中最后一个元素之后位置的迭代器（如果 end() 方法返回的迭代器）。
umap.count(key) //在容器中查找值为 key 的元素的个数。
/* 改 */
//类似python的defaultdict,当不存在的时候取默认值。
umap[i]++
/* 遍历 */
for (auto iter = umap.begin(); iter != umap.end(); ++iter) {
	cout << iter->first << " " << iter->second << endl;
}
```

