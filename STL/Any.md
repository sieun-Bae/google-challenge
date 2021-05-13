### std::any

- 복사 가능한 형식의 아무 값을 담을 수 있음
- (typesafe) void*
- 객체에 담긴 값을 꺼낼 떄는 ```std::any_cast``` 사용
- ```any_cast<variable_type>(variable_name)```
- ```typeid()```, ```variable.type()```

```
#include <iostream>
#include <any>
using namespace std;

//depth 존재, 해당 array의 원소 총합 * depth
int productSum(vector<any> array, int multiplier=1)
{
	int sum=0;
	for (auto el: array) {
		if (el.type()==typeid(vector<any>))
			sum += productSum(any_cast<any>(el), multiplier+1);
		else
			sum += any_cast<int>(el);
	}
	return sum*multiplier;
}
```

<br>

### Reference

<ul> http://occamsrazr.net/tt/entry/C17-표준-라이브러리의-stdany-소개 </ul>
