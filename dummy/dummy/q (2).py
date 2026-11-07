PYTHONHASHSEED=0
# PYTHONHASHSEED=0 환경에서 사용하세요
collision_keys = [
    "Aa", "BB",  # 이 두 개는 동일한 해시를 가짐
    "AaAa", "BBBB", "AaBB", "BBAa",  # 더 긴 충돌 문자열
    "AaAaAa", "AaAaBB", "AaBBAa", "BBAaAa", "BBBBAa",
]

# 딕셔너리에 집어넣어 성능을 확인할 수 있음
d = {}
for key in collision_keys:
    d[key] = 1

print("Aa".__hash__(), "BB".__hash__())
