
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           7/6/2020
#define _CRT_SECURE_NO_WARNINGS
#ifndef ENGINE_H
#define ENGINE_H

namespace sdds
{
	const int TYPE_MAX_SIZE = 30;

	class Engine
	{
	private:
		double m_size;
		char m_type[TYPE_MAX_SIZE + 1];

	public:
		Engine();
		Engine(const char* type, double size);
		double get() const;
		char *get_type(){return m_type;}
		void set(double size, const char* type);
		void set_engine(Engine &e);
		void display() const;
};
}
#endif
