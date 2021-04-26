### Map

- associative container: key, value pair로 저장
- balanced binary tree
- unique key: key는 중복 불가능, 중복 key는 multimap에서 가능
- ordered: 자동 정렬
- 동적 할당 (allocator)

```
#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<data type1, data type2> variable_name; //선언
	map<int> m(pred); //pred: 정렬 기준
	map<int> m2(m1); //m1을 복사한 m2 생성

	//추가, 수정
	m1.insert(pair<string, int>("HTML", 20));
	m1["HTML"] = 20;

	m.begin();
	m.end();
	m.rbegin();
	m.rend();
	m.clear();
	m.count(k);
	m.empty();
	m.insert(k);
	m.insert(iter, k);
	m.erase(start, end);
	m.find(k);
	m2.swap(m1);
	m.upper_bound(k);
	m.lower_bound(k);
	m.equal_range(k);
	m.key_comp();
	m.value_comp();
	m.size();
	m.max_size();
	m.max_element();

	return 0;
}
```

<br>

### Reference

<ul> https://blockdmask.tistory.com/87 </ul>
<ul> https://blockdmask.tistory.com/79 </ul>
