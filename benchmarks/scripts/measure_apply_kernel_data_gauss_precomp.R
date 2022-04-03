library(scattermore2)

#use premade data frame to add times with precomputed data
df <- readRDS(file="../data/measure_apply_kernel_data_gauss_old.Rda")

precomp_time = c()
for (bm in df$bitmap){
        current_data <- cbind(rnorm(10), rnorm(10)) #data size doesn't matter
        colorized <- colorize_data(current_data, out_size = c(bm, bm))

        t = system.time(apply_kernel_data(colorized, filter = "gauss"))
        bitmap <- append(bitmap, bm)
        precomp_time <- append(precomp_time, t['elapsed'])
}

df_new <- cbind(df, precomp_time)

saveRDS(df_new, file="../data/measure_apply_kernel_data_gauss.Rda")