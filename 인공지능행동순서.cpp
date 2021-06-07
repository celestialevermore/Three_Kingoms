/**
	�ϸ��� ������ �ൿ���� �ʿ��� ����Դϴ�.
	@details �ൿ���� �ʿ���� ����� ��� �� �ϸ��� �����մϴ�.
	@param self	���ؽ�Ʈ
	@param building ���� ����
	@see
	@code
	// ���� ������ ���� ��Ȯ�� �ľǵ��� �ʾ����� �Ʒ� ������ ��ũ��Ʈ���� ������ �� �ִ� �������� ��Ÿ���ϴ�.
	__ptr class __99c5228
	{
	public:
		__ptr class __99c5228__18
		{
		public:
			__get bool has_enemy3;			// 3ĭ(���� 2ĭ) �̳� �� �δ� ����
			__get bool has_enemy5;			// 5ĭ(���� 4ĭ) �̳� �� �δ� ����
			__get int own_units;			// ���� �� �ڼ��� �δ��
			__get int enemy_units;			// ���� �� �� �δ��
			__get int neighbor_enemy_units;	// ���� ���� �� �δ��
			__get int enemy_facilities;		// ���� �� �� ����ü���
			__get int player_units;			// ���� �� �÷��̾� �δ��
			__get int officers;				// �����
			__get int idle_officers;		// ��� ������ �����
			__get int status;				// ��������
			__get int required_officers;	// �ʿ��� �����
		};
	
		__get __99c5228__18 base[����_��];
	
		// �ִ� 36��
		void append(int id);
	};
				
	enum ��������
	{
		��������_�Ĺ� = 0,		// �������� �Ÿ� 2 �̻�
		��������_��� = 1,		// �������� �Ÿ� 1
		��������_���� = 2,		// ����
		��������_���� = 3,		// �����ȿ� ���� ����
	};

	enum �ΰ�����
	{
		�ΰ�����_���� = 1,
		�ΰ�����_¡�� = 2,
		�ΰ�����_���� = 3,
		�ΰ�����_���� = 4,
		�ΰ�����_�ŷ� = 5,					// ?
		�ΰ�����_�Ʒ� = 6,
		�ΰ�����_��� = 7,
		�ΰ�����_���� = 8,
		�ΰ�����_��ġ = 9,
		�ΰ�����_�������� = 10,			// ���� ���� �� ����?
		�ΰ�����_���ü��� = 11,			// ���� �� ����
		�ΰ�����_�̵� = 12,
		�ΰ�����_��ȯ = 13,
		�ΰ�����_����Ž�� = 14,
		�ΰ�����_������ = 15,
		�ΰ�����_���� = 16,
		�ΰ�����_��ȣ��� = 17,
		�ΰ�����_��ȣź�� = 18,
		�ΰ�����_������ = 19,
		�ΰ�����_Ÿ���¹����� = 20,
		�ΰ�����_ö�� = 21,
		�ΰ�����_�跫 = 22,
		�ΰ�����_�ּ�����Ž�� = 23,			// ���� ���� ���̵� �� �̸��� ����(���� ���� �� ������ ����): �ΰ�����.xml
		�ΰ�����_�ּҹ����� = 24,			// ���� ���� ���̵� �� �̸��� ����(���� ���� �� ������ �õ�): �ΰ�����.xml
		�ΰ�����_�ּ�Ÿ���¹����� = 25,	// ���� ���� 3�� �̸��� ����: �ΰ�����.xml
		�ΰ�����_�ŷ�2 = 26,				// ?
		�ΰ�����_����պ� = 27,
	};
	@endcode
*/
void PK_�ൿ����(__99c5228 self, Building building)
{
	int id = building.getId();
	__99c5228__18 base = self.base[id];

	// �ֺ� 3ĭ �ȿ� �� ����(����, �ױ��� ��� 2ĭ)
	if (base.has_enemy3)
	{
		self.append(�ΰ�����_���);
		if (id >= �ǹ�_����_���� && id < �ǹ�_����_��)
		{
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			/*
			self.append(�ΰ�����_¡��);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_ö��);
			*/

			// �÷��̾ �������� ���� ��� ��ȭ
			if (base.player_units > 0)
			{
				self.append(�ΰ�����_����);
				self.append(�ΰ�����_¡��);
				self.append(�ΰ�����_����);
				self.append(�ΰ�����_¡��);
				self.append(�ΰ�����_����);
				self.append(�ΰ�����_����);
				self.append(�ΰ�����_����);
				self.append(�ΰ�����_ö��);
			}
			else
			{
				self.append(�ΰ�����_¡��);
				self.append(�ΰ�����_����);
				self.append(�ΰ�����_����);
				self.append(�ΰ�����_ö��);
			}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		}
		return;
	}

	// ��� ������ ���� ����
	if (base.idle_officers == 0)
		return;

	// ����
	if (id >= �ǹ�_����_���� && id < �ǹ�_����_��)
	{
		int gold = building.��;

		int required_officers = base.required_officers;
		if (required_officers < 10)
			required_officers = 10;

		int total_weapons = 0;
		for (int i = 0; i < ����_����; i++)
			total_weapons += building.����[i];

		switch (base.status)
		{
		case ��������_�Ĺ�:
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�ּ�����Ž��);
			self.append(�ΰ�����_�ּҹ�����);
			self.append(�ΰ�����_�ּ�Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�ŷ�);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_���ü���);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_�̵�);
			self.append(�ΰ�����_�ŷ�2);
			self.append(�ΰ�����_¡��);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_ö��);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����պ�);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			break;

		case ��������_���:
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_���ü���);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_�̵�);
			self.append(�ΰ�����_�ּ�����Ž��);
			self.append(�ΰ�����_�ּҹ�����);
			self.append(�ΰ�����_�ּ�Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_¡��);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_�ŷ�2);
			self.append(�ΰ�����_�ŷ�);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_ö��);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����պ�);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			break;

		case ��������_����:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			/*
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_��ġ);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�ּ�����Ž��);
			self.append(�ΰ�����_�ּҹ�����);
			self.append(�ΰ�����_�ּ�Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_¡��);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_�ŷ�2);
			self.append(�ΰ�����_�ŷ�);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_ö��);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����պ�);
			self.append(�ΰ�����_���ü���);
			self.append(�ΰ�����_�̵�);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			*/

			self.append(�ΰ�����_����);
			self.append(�ΰ�����_��ġ);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�ּ�����Ž��);
			self.append(�ΰ�����_�ּҹ�����);
			self.append(�ΰ�����_�ּ�Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_ö��);
			self.append(�ΰ�����_����պ�);
			self.append(�ΰ�����_����);
			// ����� ���� ����� ��� �����ü� 2���� �Ǽ�
			if (base.officers >= required_officers && gold > 1500)
				self.append(�ΰ�����_����);
			// ���Ⱑ ���º��� ���ڸ��ٸ� ������� �켱
			if (total_weapons < building.���� - 5000)
				self.append(�ΰ�����_����);
			self.append(�ΰ�����_¡��);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_�ŷ�2);
			self.append(�ΰ�����_�ŷ�);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�̵�);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_�跫);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			break;

		case ��������_����:
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			/*
			self.append(�ΰ�����_���);
			self.append(�ΰ�����_ö��);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_¡��);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_�ŷ�);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_�ŷ�2);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			*/

			self.append(�ΰ�����_���);
			// �� ����ü��� ����
			if (base.enemy_units == 0)
			{
				self.append(�ΰ�����_����պ�);
				self.append(�ΰ�����_����);
				if (base.officers >= required_officers && gold > 1500)
					self.append(�ΰ�����_����);
			}
			// �� �δ� ����
			else
			{
				// �ڼ��� �δ� ���� ���� �ִ� ���� ���� ���� �� ���� �δ� ������ ���� ���� ö��
				if (base.own_units + base.idle_officers < base.enemy_units)
				{
					self.append(�ΰ�����_ö��);
				}
				else if (base.own_units > base.enemy_units && building.���� > 15000)
				{
					self.append(�ΰ�����_����պ�);
					self.append(�ΰ�����_����);
				}
			}
			// ���Ⱑ ���º��� ���ڸ��ٸ� ������� �켱
			if (total_weapons < building.���� - 5000)
				self.append(�ΰ�����_����);
			self.append(�ΰ�����_¡��);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_�ŷ�);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�ŷ�2);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_�跫);
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
			break;
		}
	}
	// ����, �ױ�
	else
	{
		switch (base.status)
		{
		case ��������_�Ĺ�:
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_���ü���);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_�̵�);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			break;

		case ��������_���:
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_���ü���);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_�̵�);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			break;

		case ��������_����:
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_��ġ);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_���ü���);
			self.append(�ΰ�����_�̵�);
			self.append(�ΰ�����_��������);
			self.append(�ΰ�����_�跫);
			self.append(�ΰ�����_����Ž��);
			self.append(�ΰ�����_������);
			self.append(�ΰ�����_Ÿ���¹�����);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			break;

		case ��������_����:
			self.append(�ΰ�����_���);
			self.append(�ΰ�����_�Ʒ�);
			self.append(�ΰ�����_���ü���);
			self.append(�ΰ�����_�̵�);
			self.append(�ΰ�����_���ü���);
			self.append(�ΰ�����_����);
			self.append(�ΰ�����_�跫);
			break;
		}
	}
}