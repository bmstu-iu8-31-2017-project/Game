


namespace game_module
{

	using size_type = short;
	using pair = std::pair<size_type, size_type>;
	enum unit_type {
		none = 0, army, tower, capital,
		farm, palm, pine, grave
	};

	class Result // структура результатов игры
	{

	public:

		size_type winner; // победитель игры, по умолчанию 0
		std::vector<size_type> points; // очки каждого игрока
		std::vector<size_type> last_turn; // ход выхода из игры каждого игрока
		std::vector<size_type> built_armies; // суммарная сила армий, 
											 // построенных каждым игроком за время партии
		std::vector<size_type> built_farms; // кол - во всех ферм,
											// построенных каждым игроком за время партии
		std::vector<size_type> built_towers; // суммарная сила башен, 
											 // построенных каждым игроком за время партии
		std::vector<size_type> moves; // кол - во перемещений 
									  // юнитов каждого игрока за время партии

	};

}