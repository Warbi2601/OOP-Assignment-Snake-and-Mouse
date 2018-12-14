#pragma once
class Score {
	public:
		Score();
		int get_amount() const;
		void update_amount(int);
	private:
		int amount_;
};