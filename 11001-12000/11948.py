score = []
for _ in range(6):
    score.append(int(input()))

print(sum(sorted(score[:4], reverse=True)[:3]) + sorted(score[4:], reverse=True)[0])
