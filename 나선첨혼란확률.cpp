/**
	����÷ ȥ�� Ȯ���� ����մϴ�.
	@param unit ����÷�� ����� �δ�
	@param target ��ǥ �δ�
	@param critical ���� ũ��Ƽ�� ����
*/
int PK_����÷ȥ��Ȯ��(Unit unit, Unit target, bool critical)
{
	return critical ? 100 : 30;
}