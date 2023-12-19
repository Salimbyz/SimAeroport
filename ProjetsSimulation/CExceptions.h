#ifndef CEXCEPTIONS_H
#define CEXCEPTIONS_H 
class CExceptions {
private:
	unsigned int uiEXCValeur;
public:
	/***************************************************************
	**** CExceptions() : constructeur de confort de CExceptions ****
	****
	**** Entr�e : unsigned int uiParam
	**** Necessite : NULL
	**** Retourne : NULL
	**** Entraine : On initialise uiEXCValeur tout en lui donnant
	**** la valeur uiParam
	***************************************************************/
	CExceptions(unsigned int uiParam) { uiEXCValeur = uiParam; }
	/***************************************************************
	**** uiEXCLireCode() : Accesseur en lecture de uiEXCValeur  ****
	****
	**** Entr�e : NULL
	**** Necessite : NULL
	**** Retourne : uiEXCValeur
	**** Entraine : NULL
	***************************************************************/
	unsigned int uiEXCLireCode() { return uiEXCValeur; }
	/***************************************************************
	**** uiModifierCode() : Accesseur en �criture de uiEXCValeur****
	****
	**** Entr�e : unsigned int uiCode
	**** Necessite : NULL
	**** Retourne : NULL
	**** Entraine : uiEXCValeur prend la valeur uiCode
	***************************************************************/
	void EXCModifierCode(unsigned int uiCode) { uiEXCValeur = uiCode; }
};
#endif
