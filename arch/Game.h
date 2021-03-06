#pragma once

#include "General.h"
#include "Map.h"
#include "Player.h"
#include "Hex.h"
#include "Unit.h"
#include "View.h"

namespace game_module
{
	/*!
	\brief ����� ���������� ����.
	- ������ ��� ������, ������������ � ����������� - ����.
	*/
	class Game
		: public IFullAccess
	{
	private:
		/*!
		\brief ������ ���������� �� �������, ����������� � ����.
		*/
		std::vector<Player * > Players;
		/*!
		\brief ���� ������, ������������ ��� � ������ ������.
		*/
		hex_color CurrentPlayer;
		/*!
		\brief ��������� �� ������� �����.
		*/
		Map * GameMap;
		/*!
		\brief ����� �������� �������� ����.
		- ������� ��������� ������� ��� � ��� ������. 
		���� ������� ��� �������� � ���� �� ������ ���� ���� �������, ������� ��������� � ����.
		*/
		size_type CurrentTurn;
		/*!
		\brief ����������� ��������� ���-�� ������� ����� � ����.
		- ���� ���-�� ����������� ������� ����� ��������� ����� �������� ���� ���������������.
		*/
		size_type MaxTurns;
		/*!
		\brief ���������� ������� �� ����.
		*/
		Result Results;
		/*!
		brief ��������� �� ������� ����������.
		- ���������� �������� ��������� �� ������ ������ ������.
		- ��������� ��� ���������� �������� API.
		*/
		Controller * GameController;
		/*!
		\brief ��������� �� ������ ������ �������������� ����� � ��������.
		*/
		View * GameView;
	public:
		/*!
		\brief ����������.
		- ������� ������ �� ��� ������� �����, ����������� � ���� �������, ������������� � ����.
		*/
		~Game();
		/*!
		\brief �����������.
		- �������������� ���� ������� ������ ����������� ����������.
		- �������� � ���� ��. ���� ������� ������� ����� ������� ������, 
		���� ������� ���� ��������� ������ ���-�� ������������� �����.
		- ������ ������� �����.
		- ����� �������� � ������������ � �������� ����� �����, � �� ���-��� �������.
		- ���� ���������� ���������� map_type ����� "classic", ������ ����� �� 4 �������.
		- ���� ���������� ���������� map_type ����� "duel", ������ ����� �� 2 �������.
		- ���� ���������� ���������� map_type ����� "random", ������ ����� �a 2-6 ������� 
		� ����������� �� �������� ���������� ���������� players_number. ���� ��������� �� ����� 
		� ���� ��������� ��������, �� ����� �������� �� 6 �������.
		- ���� ���������� ���������� map_type �� ����� �� ������ �������� ����,
		�� �������� ���������� "incorect_map_type".
		- �������� ������� �� �����.

		\param max_turns �������� ��� ���� MaxTurns ������� ������.
		\param dimension_x ���-�� ����� � ����������� �����.
		\param dimension_y ���-�� �������� � ����������� �����.
		\param map_type ��� ����������� �����.
		\param players_number �������� ���-�� �������.
		*/
		Game(size_type max_turns, size_type dimension_x, size_type dimension_y,
			std::string map_type, size_t players_number = 6);
		/*!
		\brief ����� �������� �� ����������� �� ����.
		- ���� ������� ������� ��� ������ ����������� ���������� ���-�� ������� ����� � ����
		��� ���� ���-�� ������� � ���� ������ ����, ���� ��������� ����������� � ������������ true.
		*/
		bool check_end_game() const;
		/*!
		\brief ������� �������� ���������� ��������� �� ���� � ����������� ������������.
		- � ������ ���� ������ ����� ��� ���������� nullptr.

		\param hex ���������� ���������� � ����������� �����.
		*/
		Hex * operator () (const Pair & hex);
		/*!
		\brief ������� �������� ���������� ��������� �� ���� � ����������� ������������.
		- � ������ ���� ������ ����� ��� ���������� nullptr.

		\param coord1 ������ ���������� ���������� � ����������� �����.
		\param coord2 ������ ���������� ���������� � ����������� �����.
		*/
		Hex * operator () (size_type coord1, size_type coord2);
		/*!
		\brief ����� ���������� ��������� �� �����, ������������ � ����� � ����������� ������������.
		- � ������ ���� ������ ����� ��� ���������� nullptr.

		\param hex ���������� �����, ��������� �� ���� �������� ���������� �������.
		*/
		Unit * get_unit(const Pair & hex);
		/*!
		\brief ����� ���������� ������ ���������� �� ���� �������, ����������� � ����.
		- ���������� ���� Players ������� ������.
		*/
		std::vector<Player *> & get_players();
		/*!
		\brief ����� ���������� ��������� �� ������, ����������� �����.
		- � ������ ���� ������ ������ ����� ��� ���������� nullptr.

		\param seek_color ���� ������, ��������� �� �������� ���������� �������.
		*/
		Player * get_player(hex_color seek_color);
		/*!
		\brief ����� ���������� ����� ���� CurrentPlayer ������� ������.
		*/
		hex_color get_current_player() const;
		/*!
		\brief ����� ���������� ������ �� ���e GameMap ������� ������.
		*/
		Map & get_game_map();
		/*!
		\brief ����� ���������� ���� CurrentTurn ������� ������.
		*/
		size_type current_turn() const;
		/*!
		\brief ����� ���������� ���� MaxTurns ������� ������.
		*/
		size_type max_turns() const;
		/*!
		\brief ����� ���������� ������ �� ���� Results ������� ������.
		*/
		Result & results();
		/*!
		\brief ����� �������� ��������� �� � ���� ����� ����������� �����.
		- � ������ ���� ������ ������ ����� ���, ���������� false.
		- ��������� ���-�� ������ �������� ������. ���� ��� ����� 0 ���������� false.

		\param color ���� ������, �������� ���������� ���������.
		*/
		bool player_in_game(hex_color color) const;
		/*!
		\brief ����� ������������� � ���� � ����������� ������������ ����������� �����.

		\param hex ���������� �����, � ������� ���������� ���������� ����.
		\param unit ��������� �� ����, ������� ���������� ���������� � ����.
		*/
		void set_unit(const Pair & hex, Unit * unit);
		/*!
		\brief ����� �������� ���� ����� � ����������� ������������ �� ����������.

		\param hex ���������� �����, ���� �������� ���������� ��������.
		\param new_color ����, � ������� ���������� ��������� ����.
		*/
		void set_color(const Pair & hex, hex_color new_color);
		/*!
		\brief ����� ��������������� ������� ������, ��� ������ ���� ������� ���.
		- �������������� ���� CurrentTurn ������� ������.
		*/
		void turn_passed();
		/*!
		\brief ����� ������������� � ���� CurrentPlayer ������� ������ ���������� ����.

		\param new_color ����, �� ������� ���������� �������� �������� ���� CurrentPlayer ������� ������.
		*/
		void set_current_player(hex_color new_color);
		/*!
		\brief ����� ������������� ���������� ���� ��� ���� ���������� ����.

		\param player_color ���� ������, ����������� � ������ ����.
		*/
		void set_winner(hex_color player_color);
		/*!
		\brief ����� ������������� ��������� ������� ��� ������ ����������� �����.

		\param player_color ���� ������ ��� ��������� ������� ��� ���������������.
		\param turn ����� ���������� �������� ���� ������ ����������� �����.
		*/
		void set_last_turn(hex_color player_color, size_type turn);
		/*!
		\brief ����� ����������� ������� ��������� ���� ���� �����, ����������� ������� ����������� �����
		�� ����, �� ���������� ��������.

		\param player_color ���� ������ ��� ������� �������������.
		\param number �����, �� ������� ������������� ������� ������ ����������� �����. �������� �� ��������� 1.
		*/
		void add_to_built_armies(hex_color player_color, size_type number = 1);
		/*!
		\brief ����� �������������� ������� ���-�� ����, ����������� ������� ����������� ����� �� ����.

		\param player_color ���� ������ ��� ������� �������������.
		*/
		void add_to_built_farms(hex_color player_color);
		/*!
		\brief ����� ����������� ������� ��������� ���� ���� �����, ����������� ������� ����������� �����
		�� ����, �� ���������� ��������.

		\param player_color ���� ������ ��� ������� �������������.
		\param number �����, �� ������� ������������� ������� ������ ����������� �����. �������� �� ��������� 2.
		*/
		void add_to_built_towers(hex_color player_color, size_type number = 2);
		/*!
		\brief ����� �������������� ������� ���-�� ����������� ����������� ������
		������� ����������� ����� �� ����.

		\param player_color ���� ������ ��� ������� �������������.
		*/
		void add_to_moves(hex_color player_color);
		/*!
		\brief ����� ������������� ������� �� �����.
		- ����������� ������� ������ ������� ��� ������������� �� �����, � ����� ���� ������������ �������
		�����, � ������� ��������� �������.
		*/
		bool place_players();
		/*!
		\brief ����� �������������� ������, ��� ��� �������, � ����.
		- ����������� �������� ����� ���� �������� ������ �������� �������� ����.
		- ������ ��������������� ������� ������ ��� ���� �����.
		- ��� ���������� ����� ������ �������� ����������� ������ �� ������ ����.
		*/
		void prepare_player();
		/*!
		\brief ����� �������� �� ����������� �������� � ����� ������� �������� ����.
		- ����������� ���������� �������� ������� ��������.
		*/
		void double_trees();
		/*!
		\brief ����� ���������� ���� ������, ������������ �� ��������� ������.
		- ���� � ���� �������� ������ ������ ������, ��� �������� ���������� �����������
		���-�� ������� ������, �����, ���� �������.
		*/
		hex_color get_winner();
		/*!
		\brief ����� ����������� ������� �� � ���������� ������ � ����������� �� ���.
		*/
		std::vector<Player *> get_bots();
		/*!
		\brief ����� ����������� ������� �������������� ���� � ��������� ��� � ����.
		*/
		void add_bot();
		/*!
		\brief ����� �������� ���� �� ������ �� ����������� �����.

		\param show_map �������� �������� ���� �� ������������� � ������ ������� ����� � ��������
		������ ������� ���. 
		�������� �� ��������� false.
		*/
		void start_game(bool show_map = false);
	};
}
