/**
	���� ���� Ȯ���� ����մϴ�.
	@param assister ������ ������ �δ�
	@param attacker ������ �δ�(������ ������ �δ�)
	@param target ��ǥ �δ�
*/
int PK_��������Ȯ��(Unit assister, Unit attacker, Unit target)
{
	Person leader(assister.����);
	int id = attacker.����;
	int bonus = ����xml(assister.����).��������Ȯ�����ʽ�;

	// ����ڳ� �������� ��� 50%
	if (leader.isFuufu(id) || leader.isGikyoudai(id))
		return std::min(50 + bonus, 100);

	// ���� Ư���� ��� �������常 �ƴϸ� 30%
	if (leader.hasSkill(Ư��_����) && !leader.isDislike(id))
		return std::min(30 + bonus, 100);

	// ģ�ֹ����� ��� 30%
	if (leader.isLike(id))
		return std::min(30 + bonus, 100);

	// �����̰� ���������� �ƴҰ�� 20%
	if (leader.isKetsuen(id) && !leader.isDislike(id))
		return std::min(20 + bonus, 100);

	return std::min(bonus, 100);
}