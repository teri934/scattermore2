library(scattermore2)

#use premade data frame to add times with precomputed data
df <- readRDS(file="data/old_gauss.Rda")

precomp_time = c()
for (d in df['data']){
    for (bm in df['bitmap']){
        current_data <- cbind(rnorm(d), rnorm(d))
        #colorized <- colorize_data(current_data, out_size = c(bm, bm))
        t = 0.5 #system.time(apply_kernel_data(colorized))

        precomp_time <- append(precomp_time, t)
    }
}

df_new <- cbind(df, precomp_time)

saveRDS(df_new, file="data/complete_gauss.Rda")