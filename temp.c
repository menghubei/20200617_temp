//由两个点的经纬度转东北直角坐标系
void  WP_Pos2XY(float lon_ref,float lat_ref, float lon,float lat, float *x,float *y)
{
    float   iPsi, Clat;
    float  dLon, dLat;

    dLon=lon-lon_ref;
    dLat=lat-lat_ref;

    iPsi = (lat_ref+lat)/Rad2Deg*0.5f;
//    Clat = cosf(iPsi);
		Clat = arm_cos_f32( iPsi);			//Ê¹ÓÃDSP¿â¼ÆËãÓàÏÒ£¬ÊäÈëÎª»¡¶ÈÖÆ
    *x = (6383487.606f*Clat - 5357.31f*arm_cos_f32(3*iPsi) )* dLon/ Rad2Deg;
    *y = (6367449.134f - 32077.0f*arm_cos_f32(2*iPsi)) * dLat / Rad2Deg; 
}

//已知经纬度及东北相对坐标系计算经纬度
void  WP_XY2Pos(float lon_ref, float lat_ref, float x, float y,  float *lon, float *lat)
{
    float  R=6378165.0f;
    float  Clat;   


    Clat = arm_cos_f32(lat_ref/Rad2Deg);

    *lon = lon_ref + x/Clat*Rad2Deg/R;
    *lat = lat_ref + y*Rad2Deg/R;
}
