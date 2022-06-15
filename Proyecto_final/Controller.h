#pragma once
#include "Lider.h"
#include "Agente.h"
#include"Aliados.h"
#include"Habitantes.h"
#include"Comodin.h"
#include"llamasdefuego.h"
#include <vector>

using namespace std;
using namespace System::Media;

class Controller {
private:
	int cont;
	int time;
	Lider* lider;
	vector<Agente*>enemies;
	vector<Aliados*>Friends;
	vector<Habitantes*> habitante;
	vector<Comodin*> comodin;
	vector<Llamas*> llamas;


public:
	Controller(Bitmap^ bmplider, Bitmap^ bmpAgente, Bitmap^ bmpAliados,Bitmap^ bmpHabitante,Bitmap^ bmpComodin,Bitmap^ BmpLlamas, int time, int Nagentes,int Nhabitantes, int hp,int  cont) {
		this->time = time; 
		this->cont = cont;

		lider = new Lider(bmplider->Width / 4, bmplider->Height / 4);
		
		//Agentes

		for (int i = 0; i < Nagentes; i++) {
			enemies.push_back(new Agente(bmpAgente->Width / 4, bmpAgente->Height / 4,rand()% 2));
		}

		// habitantes

		for (int i = 0; i < Nhabitantes; i++)
		{
			habitante.push_back(new Habitantes(bmpHabitante->Width / 4, bmpHabitante->Height / 4));
		}

		//llamas

		for (int i = 0; i < 3; i++)
		{
			llamas.push_back(new Llamas(bmpHabitante->Width / 4 , bmpHabitante->Height ,0));
		}

		//Pruebas-ejemplos-programación extra
		 
		
		// 
		//for (int  i = 0; i < 3; i++)
		//{
		//	comodin.push_back(new Comodin(bmpHabitante->Width / 4, bmpHabitante->Height / 4));
		//}
		
		//enemies.push_back(new Agente(bmpAgente->Width / 4, bmpAgente->Height / 4, 2));
	}

	~Controller() {}
	
	// Agregar aliados

	void addAliados(Aliados* g) {

		Friends.push_back(g);
		

	}

	//Agregar COMODIN

	void addcomdin(Comodin* m) {

		comodin.push_back(m);

	}

	//dibujar todo

	void drawEverything(Graphics^ g, Bitmap^ bmplider, Bitmap^ bmpAgente, Bitmap^ bmpAliados, Bitmap^ bmpHabitantes, Bitmap^ bmpComodin, Bitmap^ bmpLlamas) {

		//dibujar agentes

		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->draw(g, bmpAgente);
		}

		//dibujar habitantes

		for (int i = 0; i < habitante.size(); i++) {
			habitante[i]->draw(g, bmpHabitantes);
		}

		//dibujar comodin

		for (int i = 0; i < comodin.size(); i++)
		{
			comodin[i]->draw(g, bmpComodin);
		}

		//dibujar llamas a mi 
		for (int i = 0; i < llamas.size(); i++)
		{
			llamas[i]->draw(g, bmpLlamas);
		}

		//dibujar aliados

		//for (int i = 0; i < Friends.size(); i++) {
		//	Friends[i]->draw(g, bmpAliados);
		//}
		for (int i = 0; i < cont; i++)
		{
			for each (Aliados * b in Friends)
			{
				b->draw(g, bmpAliados);
			}
		}
		

		lider->draw(g, bmplider);
	}

	//mover todo

	void moveEverything(Graphics^ g) {

		for (int i = 0; i < llamas.size(); i++) {
			llamas[i]->move(g);
		}
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->move(g);
		}

		for (int i = 0; i < Friends.size(); i++) {
			Friends[i]->move(g, habitante[i]);
		}
	}


	Lider* getLider() { return lider; }



	void colision() {
		//Verification
		for (int i = 0; i < enemies.size(); i++) {

			if (lider->getRectangle().IntersectsWith(enemies[i]->getRectangle())) {
				enemies[i]->setVisible(false);
				if (enemies[i]->getIndex() == 0) enemies[i]->changeDxDirection();
				if (enemies[i]->getIndex() == 1) enemies[i]->changeDyDirection();
				
				lider->loseHP();

			}
		}
		for (int i = 0; i < enemies.size(); i++) {

			for (int j = 0; j < Friends.size(); j++) {

				if (enemies[i]->getRectangle().IntersectsWith(Friends[j]->getRectangle())) {
					Friends[j]->setVisible(false);
					if (enemies[i]->getIndex() == 0) enemies[i]->changeDxDirection();
					if (enemies[i]->getIndex() == 1) enemies[i]->changeDyDirection();

					lider->loseHP();
					
				}
			}
		}

		for (int i = 0; i < habitante.size(); i++)
		{
			for (int j = 0; j < Friends.size(); j++)
			{
				if (habitante[i]->getRectangle().IntersectsWith(Friends[j]->getRectangle())) {
					Friends[j]->setVisible(false);
					habitante[j]->setVisible(false);
					lider->towinHp();
				}
			}
		}

		for (int i = 0; i < comodin.size(); i++)
		{
			if (lider->getRectangle().IntersectsWith(comodin[i]->getRectangle())) {
				comodin[i]->setVisible(false);

				lider->towinHp();

			}
		}


		//Elimination
		for (int i = 0; i < Friends.size(); i++) {
			if (!Friends[i]->getVisible()) {
		      Friends.erase(Friends.begin() + i);
		
			}
		}

		for (int i = 0; i < comodin.size(); i++)
		{
			if (!comodin[i]->getVisible()){

				comodin.erase(comodin.begin() + i);

            }
			
		}
	} 

	int getTime() {
		return time;
	}
	void decreaseTime() {
		time--;
	}
};