// 서버 턴 획득 (P 연산)
sops.sem_op = -1;
if (semop(semId, &sops, 1) == -1) break;

// 클라이언트 턴 해제 (V 연산)
sops.sem_op = 1;
if (semop(semId, &sops, 1) == -1) break;
