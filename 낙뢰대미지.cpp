/**
	���� ���ط� ���
	@param[out] damage	����� ����
	@param unit			�δ�
	@param target		��ǥ
	@param critical		ũ��Ƽ��
*/
void PK_���ڴ����(__damage damage, Unit unit, HexObject target, bool critical)
{
	if (target.isInstance(kTypeIdUnit))
		damage.�������ط� = 1500 + rand(1000);
	else
		damage.�������ط� = 700 + rand(300);

	// ȸ������ ������ ��� ��ȿ
	if (isinstance(target, kTypeIdBuilding))
	{
		Building building(target);
		if (building.�ü� == �ü�_���� && !building.�Ǽ��Ϸ�)
			damage.�������ط� = 0;
	}
}