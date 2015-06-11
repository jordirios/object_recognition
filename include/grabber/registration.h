#include <libfreenect.hpp>
//#include <libfreenect_registration.h>
#include <vector>

class KinectRegistration
{
public:

	struct xypair {
		int32_t x,y;
	};

	std::vector<xypair> registration_table;
	std::vector<int32_t> depth_to_rgb_shift;
	int32_t DEPTH_X_RES,DEPTH_Y_RES; 

    int DEPTH_MAX_METRIC_VALUE;
    int DEPTH_NO_MM_VALUE;

    int REG_X_VAL_SCALE ;
    int S2D_PIXEL_CONST;
    double S2D_CONST_OFFSET;
    int DEPTH_SENSOR_X_RES;
    bool DEPTH_MIRROR_X;
    bool DENSE_REGISTRATION ;

    freenect_reg_info * regdata;
    freenect_zero_plane_info * zpi;
    Freenect::Freenect myfreenect;
    Freenect::FreenectDevice * device;
    freenect_registration reg;
    freenect_device * dev;

	KinectRegistration(bool mirror);

	void init(int depthx ,int depthy , int depthxoff, int depthyoff);

	void apply_registration( uint16_t * input_raw_mm, uint16_t* output_mm);

	void freenect_create_dxdy_tables(double* reg_x_table, double* reg_y_table, int32_t resolution_x, int32_t resolution_y );

	void SetMirror();
	
};

