/**
	���� �߰� Ȯ��
	@param unit �δ�
	@param type 0: ����, 1: ��
*/
int PK_�����߰�Ȯ��(Unit unit, int type) {
	Person leader(unit.����);
	if (leader.���� < 10000 || unit.�ŷ� < 80)
		return 0;
	else if (type == 0 && unit.hasMember(����_����))
		return 100;
	else
		return unit.�ŷ� / 2;
}