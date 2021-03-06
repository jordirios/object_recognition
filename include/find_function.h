#ifndef FIND_FUNCTION_H
#define FIND_FUNCTION_H

#include "Visualizer.h"
#include "define.h"
#include "Sampling.h"
#include "Ppfe.h"
#include "KeyDes.h"
#include "KeyPoints.h"
#include "Cluster.h"
#include <pcl/filters/statistical_outlier_removal.h>
#include "Semaphore.h"
#include <thread>
#include "Icp.h"


void FindObject (const pcl::PointCloud<PointType>::Ptr model, const pcl::PointCloud<PointType>::Ptr&  original_scene, Semaphore& s, 
	             std::vector<ClusterType>& found_models,const  int id, const float filter, const int icp_iteration, ErrorWriter & e, const int &frame_index);

#endif