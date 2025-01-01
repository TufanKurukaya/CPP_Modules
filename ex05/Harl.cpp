#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "DEBUG:\n7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastırması yemeyi seviyorum. Gerçekten seviyorum!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "INFO:\nEkstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıyorum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını istemezdim!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "WARNING:\nBence bedavaya fazladan pastırma yemeyi hak ediyorum. Ben yıllardır geliyorum, sen geçen aydan beri burada çalışmaya başladın." << std::endl;
}

void Harl::error( void )
{
	std::cout << "ERROR:\nBu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << std::endl;
}


void Harl::complain( std::string level )
{
	int i = 0;
	void (Harl::*funks[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	const std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	while (i < 4 && levels[i] != level)
		i++;
	if (i < 4)
		(this->*funks[i])();
}
