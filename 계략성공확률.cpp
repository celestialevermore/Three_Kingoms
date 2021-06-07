/**
	�跫 ���� Ȯ���� ����մϴ�.
	@param[out] blocked ���� ����
	@param src ���� �δ�
	@param src_pos ���� ��ǥ
	@param dst_pos ��ǥ ��ǥ
	@param strategy #�跫Id
	@return Ȯ��
*/
int PK_�跫_����Ȯ��(bool &out blocked, Unit src, Point src_pos, Point dst_pos, int strategy)
{
	blocked = false;

	if (!isalive(src))
		return 0;

	int src_int = src.����;
	int dst_int = 0;
	Unit dst;
	Hex dst_hex(dst_pos);
	int a = 0;
	int result = 0;
	int bonus = ����xml(src.����).�跫����Ȯ�����ʽ�;

	// ��ǥ �δ� ����
	if (dst_hex.hasUnit())
	{
		dst = dst_hex.getUnit();
		dst_int = dst.����;
		// ��ǥ �δ� ���� ȥ��
		if (dst.���� == �δ����_ȥ��)
			a = 10;
	}

	// ���� �ƴ�, ��ǥ �δ� ����
	if (strategy != �跫_���� && dst)
	{
		// ��ǥ �δ� ���� ����
		if (dst.isEnemy(src))
		{
			// ��ǥ �δ� ���� Ư�� ����
			if (dst.hasSkill(Ư��_����))
			{
				blocked = true;
				return 0;
			}
		}
	}

	switch (strategy)
	{
	case �跫_ȭ��:
		do {
			int b = 0;
			if (dst_hex.hasBuilding())
				b = ȭ��_�ü�factor(dst_hex.getBuilding().�ü�);
			else
				b = ȭ��_����factor(dst_hex.����);

			if (b == 100)
				return b;

			int c = 100;
			c -= dst_int * 90 / 100;
			c /= 2;
			c *= src_int * src_int * 100;
			c /= dst_int * dst_int + src_int * src_int;
			c /= 55;
			c -= (100 - src_int) / 10;
			c += a;
			c += (b / 2) - 5;

			// ��ǥ ������Ʈ ���º��� ����
			if (src_int < dst_int)
				c -= (dst_int - src_int) / 3;

			if (c < 1)
				c = 1;

			int d = a + (src_int * 30 / 100) - (dst_int / 5) + 55;

			// ��ǥ �δ� ����
			if (!dst)
				d += 10;

			result = std::max(1, std::min(c, d, 99));

			// ��ǥ �δ� ����
			if (dst)
			{
				// ��ǥ �δ� ȭ�� Ư�� ����
				if (dst.hasSkill(Ư��_ȭ��) ||
					// ��ǥ �δ� ���� Ư�� ������ ���º��� ����
					dst.getBestMemberStat(Ư��_����, ����ɷ�_����) > src_int ||
					// ��ǥ �δ� �Ż� Ư�� ������ ���º��� ����
					dst.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > src_int)
				{
					blocked = true;
					return 0;
				}

				// ȭ�� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				if (src.getBestMemberStat(Ư��_ȭ��, ����ɷ�_����) > dst_int ||
					// ��� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
					src.getBestMemberStat(Ư��_���, ����ɷ�_����) > dst_int ||
					// ȭ�� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
					src.getBestMemberStat(Ư��_ȭ��, ����ɷ�_����) > dst_int ||
					// �Ż� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
					src.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > dst_int)
				{
					return 100;
				}
			}
		} while (false);
		break;

	case �跫_��ȭ:
		do {
			// ȭ�� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (src.getBestMemberStat(Ư��_ȭ��, ����ɷ�_����) > dst_int ||
				// ��� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_���, ����ɷ�_����) > dst_int ||
				// ȭ�� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_ȭ��, ����ɷ�_����) > dst_int ||
				// �Ż� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > dst_int)
			{
				return 100;
			}

			float b = std::max(src.���� - 5, 10);
			float c = sqrt(b) * 11.f;
			int d = int(c);

			result = std::max(1, std::min(d, 99));
		} while (false);
		break;

	case �跫_����:
		do {
			// ��ǥ �δ� ����
			if (!isalive(dst))
				return 0;

			// ��ǥ �δ� ����
			if (dst)
			{
				// ��ǥ �δ� ���� Ư�� ����
				if (dst.hasSkill(Ư��_����) ||
					// ��ǥ �δ� ��� Ư�� ����
					dst.hasSkill(Ư��_���))
				{
					blocked = true;
					return 0;
				}
			}

			// �� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (src.getBestMemberStat(Ư��_��, ����ɷ�_����) > dst_int ||
				// ��� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_���, ����ɷ�_����) > dst_int ||
				// �Ż� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > dst_int)
			{
				return 100;
			}

			// ��ǥ �δ� ����
			if (dst)
			{
				// ��ǥ �δ� ���� Ư�� ������ ���º��� ����
				if (dst.getBestMemberStat(Ư��_����, ����ɷ�_����) > src_int ||
					// ��ǥ �δ� �Ż� Ư�� ������ ���º��� ����
					dst.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > src_int)
				{
					blocked = true;
					return 0;
				}
			}

			int b = ����_����factor(Person(dst.����).����);
			int c = src.�ŷ� / 20;
			int d = src_int * 30 / 100;

			d -= dst_int / 5;
			d += c;
			d += b;

			int e = a + d + 70;

			int f = 100;

			f -= dst_int * 90 / 100;
			f *= src_int * src_int * 100;
			f /= dst_int * dst_int + src_int * src_int;
			f /= 55;
			f -= (100 - src_int) / 10;
			f += c;
			f += b;
			f += a;

			// ��ǥ ������Ʈ ���º��� ����
			if (src_int < dst_int)
				f -= (dst_int - src_int) / 3;

			if (f < 1)
				f = 1;

			result = std::max(1, std::min(e, f, 99));
		} while (false);
		break;

	case �跫_����:
		do {
			// ��ǥ �δ� ����
			if (!isalive(dst))
				return 0;

			// ��ǥ �δ� ����
			if (dst)
			{
				// ��ǥ �δ� ħ�� Ư�� ����
				if (dst.hasSkill(Ư��_ħ��) ||
					// ��ǥ �δ� ��� Ư�� ����
					dst.hasSkill(Ư��_���))
				{
					blocked = true;
					return 0;
				}
			}

			// �ⷫ Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (src.getBestMemberStat(Ư��_�ⷫ, ����ɷ�_����) > dst_int ||
				// ��� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_���, ����ɷ�_����) > dst_int ||
				// �Ż� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > dst_int)
			{
				return 100;
			}

			// ��ǥ �δ� ����
			if (dst)
			{
				// ��ǥ �δ� ���� Ư�� ������ ���º��� ����
				if (dst.getBestMemberStat(Ư��_����, ����ɷ�_����) > src_int ||
					// ��ǥ �δ� �Ż� Ư�� ������ ���º��� ����
					dst.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > src_int)
				{
					blocked = true;
					return 0;
				}
			}

			int b = ����_����factor(Person(dst.����).����);
			int c = dst.��� / 20;
			int d = src_int * 30 / 100;

			d -= dst_int / 5;
			d += c;
			d += b;

			int e = a + d + 70;

			int f = 100;

			f -= dst_int * 90 / 100;
			f *= src_int * src_int * 100;
			f /= dst_int * dst_int + src_int * src_int;
			f /= 45;
			f -= (100 - src_int) / 10;
			f += c;
			f += b;
			f += a;

			// ��ǥ ������Ʈ ���º��� ����
			if (src_int < dst_int)
				f -= (dst_int - src_int) / 3;

			if (f < 1)
				f = 1;

			result = std::max(1, std::min(e, f, 99));
		} while (false);
		break;

	case �跫_����:
		do {
			// ��ǥ �δ� ����
			if (!isalive(dst))
				return 0;

			// ��� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (src.getBestMemberStat(Ư��_���, ����ɷ�_����) > dst_int ||
				// �Ż� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > dst_int)
			{
				return 100;
			}

			float b = std::max(src.���� - 5, 10);
			float c = sqrt(b) * 11.f + ����_����factor(Person(dst.����).����);
			int d = int(c);

			result = std::max(1, std::min(d, 99));
		} while (false);
		break;

	case �跫_����:
		do {
			// ��ǥ �δ� ����
			if (!isalive(dst))
				return 0;

			// ��� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (src.getBestMemberStat(Ư��_���, ����ɷ�_����) > dst_int ||
				// �Ż� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > dst_int)
			{
				return 100;
			}

			// ��ǥ �δ� ����
			if (dst)
			{
				// ��ǥ �δ� ���� Ư�� ������ ���º��� ����
				if (dst.getBestMemberStat(Ư��_����, ����ɷ�_����) > src_int ||
					// ��ǥ �δ� �Ż� Ư�� ������ ���º��� ����
					dst.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > src_int)
				{
					blocked = true;
					return 0;
				}
			}

			int b = ����_����factor(Person(dst.����).����);
			int c = (src.���� - dst.���) / 10;
			int d = src_int * 30 / 100;

			d -= dst_int / 3;
			d += b;
			d += c;

			int e = a + d + 80;

			int f = 100;

			f -= dst_int * 90 / 100;
			f *= src_int * src_int * 100;
			f /= dst_int * dst_int + src_int * src_int;
			f /= 50;
			f -= (100 - src_int) / 10;
			f += b;
			f += c;
			f += a;

			// ��ǥ ������Ʈ ���º��� ����
			if (src_int < dst_int)
				f -= (dst_int - src_int) / 3;

			if (f < 1)
				f = 1;

			result = std::max(1, std::min(e, f, 99));
		} while (false);
		break;

	case �跫_����:
		do {
			// ��ǥ �δ� ����
			if (!isalive(dst))
				return 0;

			// �˰� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
			if (src.getBestMemberStat(Ư��_�˰�, ����ɷ�_����) > dst_int ||
				// ��� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_���, ����ɷ�_����) > dst_int ||
				// �Ż� Ư�� ������ ������ ��ǥ ������Ʈ ���º��� ����
				src.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > dst_int)
			{
				return 100;
			}

			// ��ǥ �δ� ����
			if (dst)
			{
				// ��ǥ �δ� ���� Ư�� ������ ���º��� ����
				if (dst.getBestMemberStat(Ư��_����, ����ɷ�_����) > src_int ||
					// ��ǥ �δ� �Ż� Ư�� ������ ���º��� ����
					dst.getBestMemberStat(Ư��_�Ż�, ����ɷ�_����) > src_int)
				{
					blocked = true;
					return 0;
				}
			}

			int b = ����_����factor(Person(dst.����).����);
			int c = dst_int * 40 / 100;
			int d = src_int * 30 / 100 - c + b;
			int e = a + d + 70;

			int f = 100;
			f -= dst_int * 90 / 100;
			f *= src_int * src_int * 100;
			f /= dst_int * dst_int + src_int * src_int;
			f /= 55;
			f -= (100 - src_int) / 10;
			f += b;
			f += a;

			// ��ǥ ������Ʈ ���º��� ����
			if (src_int < dst_int)
				f -= (dst_int - src_int) / 3;

			if (f < 1)
				f = 1;

			result = std::max(1, std::min(e, f, 99));
		} while (false);
		break;

	case �跫_���:
		do {
			// ��ǥ �δ� ����
			if (!isalive(dst))
				return 0;

			int b = ����_����factor(Person(dst.����).����);
			int c = 100 - (dst_int * 90 / 100);
			int d = src_int / 10;

			d += b;
			d += c;
			d += a;

			// ��ǥ �δ� ������ �� ����
			if (dst_int > src_int)
			{
				b -= (100 - src_int) / 10;
				b += c;
				d = a + b - 5;
			}

			result = std::max(1, std::min(d, 99));
			return std::min(result + bonus, 100);
		} while (false);
		break;

	case �跫_����:
		do {
			int b = src_int * 60 / 100;
			int c = a + b + 15;
			result = std::max(1, std::min(c, 99));
			return std::min(result + bonus, 100);
		} while (false);
		break;
	}

	// �汹 Ư�� ����
	if (src.hasSkill(Ư��_�汹))
	{
		// ��ǥ �δ� ���� ���� ����
		if (isalive(dst) && !dst.hasFemaleMember())
			result *= 2;
	}

	return std::min(result + bonus, 100);
}

int ȭ��_�ü�factor(int id)
{
	switch (id)
	{
	case �ü�_����:
	case �ü�_����:
	case �ü�_��ä:
	case �ü�_����:
	case �ü�_��������:
	case �ü�_���۴�:
		return 10;

	case �ü�_�ױ�:
	case �ü�_�����:
	case �ü�_������:
	case �ü�_�°��:
	case �ü�_���Ǵ�:
	case �ü�_������1:
	case �ü�_����:
	case �ü�_��:
	case �ü�_����:
	case �ü�_����:
	case �ü�_����:
	case �ü�_����:
	case �ü�_��â:
	case �ü�_�Ͻ���:
	case �ü�_���г�:
	case �ü�_����2��:
	case �ü�_����3��:
		return 30;

	case �ü�_��:
		return 35;

	case �ü�_���:
		return 25;

	case �ü�_�ó�:
	case �ü�_������2:
	case �ü�_����:
	case �ü�_����:
	case �ü�_���尣:
	case �ü�_������:
	case �ü�_������:
	case �ü�_�����:
	case �ü�_�����:
	case �ü�_�ܱ���:
	case �ü�_�跫��:
	case �ü�_������:
	case �ü�_�����:
	case �ü�_�����:
	case �ü�_����2��:
	case �ü�_����3��:
	case �ü�_����2��:
	case �ü�_����3��:
	case �ü�_���尣2��:
	case �ü�_���尣3��:
	case �ü�_������2��:
	case �ü�_������3��:
		return 40;

	case �ü�_���:
	case �ü�_����:
		return 20;

	case �ü�_�Ҿ�:
	case �ü�_ȭ����:
	case �ü�_ȭ��:
	case �ü�_ȭ����:
	case �ü�_ȭ��:
	case �ü�_��ȭ��:
	case �ü�_��ȭ��:
		return 100;

	case �ü�_����:
	case �ü�_������:
	case �ü�_���:
	case �ü�_�强:
		return 0;
	}
	return 0;
}

int ȭ��_����factor(int id)
{
	switch (id)
	{
	case ����_�ʿ�: return 40;
	case ����_��: return 40;
	case ����_��: return 40;
	case ����_����: return 10;
	case ����_��õ: return 10;
	case ����_��: return 50;
	case ����_��: return 0;
	case ����_��: return 0;
	case ����_�ٴ�: return 0;
	case ����_Ȳ����: return 35;
	case ����_�ֿ䵵��: return 30;
	case ����_������: return 15;
	case ����_�ٸ�: return 20;
	case ����_��������: return 10;
	case ����_�ؾ�: return 0;
	case ����_���: return 0;
	case ����_����: return 0;
	case ����_����: return 0;
	case ����_�ױ�: return 0;
	case ����_������: return 10;
	}
	return 0;
}

int ����_����factor(int id)
{
	switch (id)
	{
	case ����_�ҽ�: return 3;
	case ����_����: return 1;
	case ����_���: return 0;
	case ����_����: return -2;
	}
	return 0;
}

int ����_����factor(int id)
{
	switch (id)
	{
	case ����_�ҽ�: return -2;
	case ����_����: return 0;
	case ����_���: return 1;
	case ����_����: return 3;
	}
	return 0;
}

int ����_����factor(int id)
{
	switch (id)
	{
	case ����_�ҽ�: return -5;
	case ����_����: return 5;
	case ����_���: return 0;
	case ����_����: return -10;
	}
	return 0;
}

int ����_����factor(int id)
{
	switch (id)
	{
	case ����_�ҽ�: return 3;
	case ����_����: return -2;
	case ����_���: return 0;
	case ����_����: return 1;
	}
	return 0;
}

