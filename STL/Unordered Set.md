### Undrdered Set

- 기존 std::set 의 경우 삽입, 삭제가 빈번할 경우 느려지는 문제
- std::set 은 키를 저장하는 이진탐색트리, 탐색 O(logN)
- 따라서 자동으로 정렬하지 않는 unordered set 사용
- 해쉬테이블, O(1) ~ O(N), 버킷이 존재하기에 메모리 사용량이 증가함

```
#include <iostream>
#include <unordered_set>
#include <string>

int main()
{
	std::unordered_set<std::string> names;
	names.insert("Victor");
	names.insert("Lulu");
	names.insert("Mocha");

	for (auto it = names.begin(); it != names.end(); ++it) {
		std::cout << *it << std::endl;
	}

	return 0;
}
```

<br>

### Reference

<ul> https://m.blog.naver.com/PostView.nhn?blogId=babobigi&logNo=220896177541&proxyReferer=https:%2F%2Fwww.google.com%2F </ul>
<ul> https://hack-gogumang.tistory.com/413 </ul>
