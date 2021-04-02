# CVECTOR
**Portfolio, Dynamic List, C99 "CVector"**<br>
c언어 공부용으로 만든 동적 리스트 구조입니다.<br>
<br>
GPL-v3.0 혹은 그 이후 버전으로 배포됩니다.
# DOCS
## src/vector.h
### vector* vcalloc()
새로운 `vector`를 생성하고 반환합니다<br>
`malloc`에 실패했다면 `NULL`을 반환합니다.
### void vcfree(vector* vc)
`vc`를 삭제합니다
### void vcresz(vector* vc, int siz)
`vc`의 크기를 `siz`로 설정합니다
### void *vcpush(vector* vc, void* obj)
`vc`에 `obj`를 추가합니다.<br>
이 작업은 `vc`의 사이즈를 1 증가시킵니다.<br>
**`obj`는 포인터 변수이거나 `src/env.h`가 선언하는 `PTRSIZ`보다 작거나 같아야 합니다.**
### void *vcpop(vector* vc)
`vc`의 맨 뒤에 있는 오브젝트를 삭제하고 반환합니다.<br>
이 작업은 `vc`의 사이즈를 1 감소시킵니다.
### void *vcsift(vector* vc)
`vc`의 맨 앞에 있는 오브젝트를 삭제하고 반환합니다.<br>
이 작업은 `i > 0`인 모든 오브젝트의 인덱스를 1씩 감소시키고, `vc`의 사이즈를 1 감소시킵니다.
### void vcusft(vector* vc, void* obj)
`vc`의 맨 앞에 `obj`를 추가합니다.<br>
이 작업은 `i > 0`인 모든 오브젝트의 인덱스를 1씩 증가시키고, `vc`의 사이즈를 1 증가시킵니다.<br>
**`obj`는 포인터 변수이거나 `src/env.h`가 선언하는 `PTRSIZ`보다 작거나 같아야 합니다.**
### void *vcrmov(vector* vc, void* obj, int idx)
`vc`의 `idx`에 있는 오브젝트를 삭제하고 반환합니다.<br>
이 작업은 `i > idx`인 모든 오브젝트의 인덱스를 1씩 감소시키고,
`vc`의 사이즈를 1 감소시킵니다.
### void vcisrt(vector* vc, void* obj, int idx)
`vc`의 `idx`에 `obj`를 삽--1--입합니다.<br>
이 작업은 `i >= idx`인 모든 오브젝트의 인덱스를 1씩 증가시키고, `vc`의 사이즈를 1 증가시킵니다.<br>
**`obj`는 포인터 변수이거나 `src/env.h`가 선언하는 `PTRSIZ`보다 작거나 같아야 합니다.**
### void vcidxo(vector* vc, void* obj)
`vc`에 있는 오브젝트중 `obj`와 일치하는 오브젝트들중 첫번째 인덱스를 반환합니다.<br>
일치하는게 없다면 -1을 반환합니다<br>
**`obj`는 포인터 변수이거나 `src/env.h`가 선언하는 `PTRSIZ`보다 작거나 같아야 합니다.**
### void vcadds(vector* zu, vector* von)
`zu`에 `von`에 있는 모든 오브젝트를 추가시킵니다.<br>
이 작업은 `zu`의 사이즈를 `von`의 사이즈만큼 증가시킵니다.
### vector *vccmpr(vector* ein, vector* zwi)
`ein`과 `zwi`를 합친 새 `vector`를 반환합니다.