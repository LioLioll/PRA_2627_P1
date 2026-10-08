#ifndef ROBOTICARM_H
#define ROBOTICARM_H

class RoboticArm{
	private:
		double x;
		double y;
		double z;
		bool sujetando;

	public:
		RoboticArm(double x, double y, double z, bool sujetando);

		double getX();
		double getY();
		double getZ();
		bool getSujetando();

		void grab();
		void release();
		void move(double x, double y, double z);
	};

	#endif
