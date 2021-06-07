/**
	�δ� ȥ�� ���θ� ����մϴ�.
	@param unit �δ�
*/
bool PK_�δ�ȥ��(Unit unit)
{
	int troops = unit.����;
	if (troops >= 1000)
		return false;

	if (unit.���� != �δ����_���)
		return false;

	// ���� �� 8% + 10 Ȯ���� ȸ��
	if (randbool(std::min(std::max(troops * 8 / 100 + 10, 10), 90)))
		return false;

	// ��� 20% + 20 Ȯ���� ȸ��
	if (randbool(unit.��� / 5 + 20))
		return false;

	__func_59b130 f;
	f.src = unit;
	Map().range(unit.��ǥ, 1, 4, RingCallbackType(f.callback));

	if (f.max_enemy_troops < 500)
		return false;

	// �� �δ� ���� ���� �ڼ��� �δ� ���� ���� 1/5�� �ȵ� ��� 60% Ȯ���� ȸ��
	if (f.sum_enemy_troops < f.sum_own_troops / 5)
	{
		if (randbool(60))
			return false;
	}
	// �� �δ� ���� ���� �ڼ��� �δ� ���� ���� 1/2�� �ȵ� ��� 40% Ȯ���� ȸ��
	else if (f.sum_enemy_troops < f.sum_own_troops / 2)
	{
		if (randbool(40))
			return false;
	}

	// ���� ���� 20���� ���� �� �δ� �� �ִ� ���� ������ ����
	// ���� ���� 40���� ���� �� �δ� ���� �պ��� ���ٸ� ȸ��
	if (troops * 20 >= f.max_enemy_troops && troops * 40 >= f.sum_enemy_troops)
		return false;

	return true;
}

class __func_59b130
{
	bool callback(Hex hex, Point pos)
	{
		if (!hex.hasUnit())
			return false;

		Unit dst = hex.getUnit();
		if (!isalive(dst))
			assert(false);

		if (dst.���� != �δ����_���)
			return false;

		// �� �δ�
		if (src.isEnemy(dst))
		{
			int troops = dst.����;
			sum_enemy_troops += troops;
			if (troops > max_enemy_troops)
				max_enemy_troops = troops;
		}
		// �ڼ��� �δ�
		else if (src.isOwn(dst))
		{
			// �̿� ��ǥ
			if (Map().isNeighbor(src.��ǥ, dst.��ǥ))
				sum_own_troops += dst.����;
		}

		return false;
	}

	Unit src;
	int max_enemy_troops = 0; // 3ĭ ���� �� �δ� �� �ִ� ����
	int sum_enemy_troops = 0; // 3ĭ ���� �� �δ� ���� ��
	int sum_own_troops = 0;   // ���� �ڼ��� �δ� ���� ��
};