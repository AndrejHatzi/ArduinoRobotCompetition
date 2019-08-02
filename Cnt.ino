
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void contornar(void)
{
  sonar_dist_esq_dir();
  if (DistEsq >= DistDir)                       contornar_pela_esq_sonar_dir();
  else if (DistEsq < DistDir)                  contornar_pela_dir_sonar_esq();
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

